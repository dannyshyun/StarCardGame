#pragma once
#include <System/Scene.h>
#include <System/Component/Component.h>
#include <System/Component/ComponentSpringArm.h>

class ComponentObjectController : public Component
{
public:
    BP_COMPONENT_TYPE( ComponentObjectController, Component );

    void Init() override { __super::Init(); }

    void Update() override
    {
        __super::Update();

        // オーナー(自分がAddComponentされたObject)を取得します
        // 処理されるときは必ずOwnerは存在しますので基本的にnullptrチェックは必要ありません
        auto owner = GetOwner();

        float3 vec{ 0, 0, 0 };
        float3 dir{ 0, 0, 0 };
        if( IsKey( key_up_ ) )
            dir += { 0, 0, -1 };

        if( IsKey( key_down_ ) )
            dir += { 0, 0, 1 };

        if( IsKey( key_right_ ) )
            dir += { -1, 0, 0 };

        if( IsKey( key_left_ ) )
            dir += { 1, 0, 0 };

        if( (float)length( dir ) > 0.0f )
        {
            dir = normalize( dir );

            owner->AddTranslate( dir * speed_, true );

            // モデルを移動の方向に向けます
            if( auto mdl = owner->GetComponent<ComponentModel>() )
            {
                mdl->SetRotationToVectorWithLimit( dir, rot_speed_ );
                mdl->PlayAnimationNoSame( "run", true );
            }
        }
        else
        {
            // モデルを移動の方向に向けます
            if( auto mdl = owner->GetComponent<ComponentModel>() )
                mdl->PlayAnimationNoSame( "idle", true );
        }

        if( auto camera = Scene::GetCurrentCamera().lock() )
        {
            auto cam_owner = camera->GetOwner();
            if( auto arm = cam_owner->GetComponent<ComponentSpringArm>() )
            {
                // SpringArmのオブジェクトが自分の場合のみ
                auto obj = arm->GetSpringArmObject().lock();
                if( obj.get() == owner )
                {
                    // ターゲットがいる場合
                    if( auto target = target_.lock() )
                    {
                        // 徐々に敵の方に向ける(1フレーム最大3度)
                        owner->SetRotationToPositionWithLimit(
                            target->GetTranslate(),
                            target_cam_side_speed_ * GetDeltaTime60() );

                        // カメラローテーションをロック方向にしておくと
                        // 戻った時に違和感がない
                        cam_ry_ = owner->GetRotationAxisXYZ().y;
                        cam_rx_ = ( cam_rx_ + target_cam_up_down ) * 0.95f -
                                  target_cam_up_down;

                        arm->SetSpringArmRotate( { cam_rx_, 0, 0 } );
                    }
                    else
                    {
                        float mouse_ud = mouse_up_down_ * GetDeltaTime60();
                        float mouse_lr = mouse_left_right_ * GetDeltaTime60();
                        float cam_spd  = cam_speed_ * GetDeltaTime60();
                        if( use_mouse_ )
                        {
                            cam_rx_ += GetMouseMoveY() * ( mouse_ud / 100.0f );
                            if( cam_rx_ > limit_cam_up_ )
                                cam_rx_ = limit_cam_up_;
                            if( cam_rx_ < limit_cam_down_ )
                                cam_rx_ = limit_cam_down_;
                            cam_ry_ += GetMouseMoveX() * ( mouse_lr / 100.0f );
                            if( cam_ry_ > 360.0f )
                                cam_ry_ -= 360.0f;
                            if( cam_ry_ < -360.0f )
                                cam_ry_ += 360.0f;
                        }
                        if( IsKey( cam_up_ ) )
                        {
                            cam_rx_ += cam_spd;
                            if( cam_rx_ > limit_cam_up_ )
                                cam_rx_ = limit_cam_up_;
                        }
                        if( IsKey( cam_down_ ) )
                        {
                            cam_rx_ -= cam_spd;
                            if( cam_rx_ < limit_cam_down_ )
                                cam_rx_ = limit_cam_down_;
                        }
                        if( IsKey( cam_right_ ) )
                        {
                            cam_ry_ += cam_spd;
                            if( cam_ry_ > 360.0f )
                                cam_ry_ -= 360.0f;
                        }
                        if( IsKey( cam_left_ ) )
                        {
                            cam_ry_ -= cam_spd;
                            if( cam_ry_ < -360.0f )
                                cam_ry_ += 360.0f;
                        }

                        // Y軸はオブジェクトそのものの向きを使う
                        owner->SetRotationAxisXYZ( { 0, cam_ry_, 0 } );
                        // 上下はSpringArmで制御しておく
                        arm->SetSpringArmRotate( { cam_rx_, 0, 0 } );
                    }
                }
            }
        }
    }

    void        SetSpeed( const float speed ) { speed_ = speed; }
    const float GetSpeed() const { return speed_; }

    void SetKeys( int up, int down, int left, int right )
    {
        key_up_    = up;
        key_down_  = down;
        key_left_  = left;
        key_right_ = right;
    }

    void SetCameraKeys( int up, int down, int left, int right )
    {
        cam_up_    = up;
        cam_down_  = down;
        cam_left_  = left;
        cam_right_ = right;
    }

    void SetTarget( ObjectPtr target ) { target_ = target; }

    void GUI() override
    {
        __super::GUI();

        ImGui::Begin( GetOwner()->GetName().data() );
        {
            ImGui::Separator();
            if( ImGui::TreeNode( u8"ComponentObjectController" ) )
            {
                // GUI上でオーナーから自分(SampleObjectController)を削除します
                if( ImGui::Button( u8"削除" ) )
                    GetOwner()->RemoveComponent( shared_from_this() );

                ImGui::DragFloat( u8"移動速度", &speed_, 0.1f );
                ImGui::DragFloat( u8"移動回転角度", &rot_speed_, 1.0f );

                ImGui::Checkbox( u8"カメラ方向にMouseを使用", &use_mouse_ );
                ImGui::DragFloat( u8"カメラ左右回転スピード",
                                  &mouse_left_right_ );
                ImGui::DragFloat( u8"カメラ上下回転スピード", &mouse_up_down_ );

                ImGui::DragFloat( u8"見る方向上リミット", &limit_cam_up_ );
                ImGui::DragFloat( u8"見る方向下リミット", &limit_cam_down_ );

                ImGui::TreePop();
            }
        }
        ImGui::End();
    }

protected:
    float speed_     = 1.0f;
    float rot_speed_ = 5.0f;

    int key_up_    = KEY_INPUT_W;
    int key_down_  = KEY_INPUT_S;
    int key_left_  = KEY_INPUT_A;
    int key_right_ = KEY_INPUT_D;

    float cam_speed_ = 1.0f;
    int   cam_up_    = KEY_INPUT_UP;
    int   cam_down_  = KEY_INPUT_DOWN;
    int   cam_left_  = KEY_INPUT_LEFT;
    int   cam_right_ = KEY_INPUT_RIGHT;

    float cam_rx_ = -20.f;
    float cam_ry_ = 0;

    bool  use_mouse_        = true;
    float mouse_up_down_    = 10.0f;
    float mouse_left_right_ = 10.0f;

    float limit_cam_up_   = 5.0f;    //!< 上を眺める
    float limit_cam_down_ = -45.0f;  //!< 下を見る

    ObjectWeakPtr target_;
    float         target_cam_side_speed_ = 3.0f;  //!< ロックオン時のカーソル移動速度
    float target_cam_up_down = 10.0f;  //!< ターゲットを見る際の上下固定

    //--------------------------------------------------------------------
    //! @name Cereal処理
    //--------------------------------------------------------------------
    //@{

    //! @brief セーブ
    // @param arc アーカイバ
    // @param ver バージョン
    CEREAL_SAVELOAD( arc, ver )
    {
        arc( CEREAL_NVP( speed_ ),
             CEREAL_NVP( rot_speed_ ),

             CEREAL_NVP( key_up_ ),
             CEREAL_NVP( key_down_ ),
             CEREAL_NVP( key_left_ ),
             CEREAL_NVP( key_right_ ),

             CEREAL_NVP( cam_speed_ ),
             CEREAL_NVP( cam_up_ ),
             CEREAL_NVP( cam_down_ ),
             CEREAL_NVP( cam_left_ ),
             CEREAL_NVP( cam_right_ ),

             CEREAL_NVP( cam_rx_ ),
             CEREAL_NVP( cam_ry_ ),

             CEREAL_NVP( limit_cam_up_ ),
             CEREAL_NVP( limit_cam_down_ ),

             CEREAL_NVP( target_ ),
             CEREAL_NVP( target_cam_side_speed_ ),
             CEREAL_NVP( target_cam_up_down ) );

        arc( cereal::make_nvp( "Component",
                               cereal::base_class<Component>( this ) ) );
    }
};

BP_COMPONENT_IMPL( ComponentObjectController, u8"移動コンポーネント" );

CEREAL_REGISTER_TYPE( ComponentObjectController )
CEREAL_REGISTER_POLYMORPHIC_RELATION( Component, ComponentObjectController )
