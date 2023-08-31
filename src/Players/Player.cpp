#include <WinMain.h>
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionCapsule.h>
#include <System/Component/ComponentObjectController.h>
#include "Camera/Camera.h"
#include "Player.h"

class PlayerController : public ComponentObjectController
{
public:
    BP_COMPONENT_TYPE( PlayerController, ComponentObjectController );
    void Init() override;
    void Update() override;

private:
    void PlayerUpdate();
    void CameraUpdate();
    void Dash();

private:
    Object* player{};
    bool    throwing{};
    bool    prethrowing{};
    bool    dashing{};
};

CEREAL_REGISTER_TYPE( PlayerController )
CEREAL_REGISTER_POLYMORPHIC_RELATION( ComponentObjectController,
                                      PlayerController )
BP_OBJECT_IMPL( Player, "Player" );
PlayerPtr Player::Create( float3 pos )
{
    auto obj = Scene::CreateObjectPtr<Player>();
    obj->SetName( "Player" );
    obj->pos = pos;
    return obj;
}

bool Player::Init()
{
    if( ! Super::Init() )
        return false;
    // modle
    auto mdl = AddComponent<ComponentModel>( "data/Model/Ch46.mv1" );
    mdl->SetScaleAxisXYZ( 0.01f );
    // animation
    mdl->SetAnimation( {
        { "idle",                 "data/Animation/Ch46/Idle.mv1", 0,  1.f},
        {"throw",        "data/Animation/Ch46/Frisbee Throw.mv1", 0, 1.5f},
        {  "run",              "data/Animation/Ch46/Running.mv1", 0,  1.f},
        { "dash",                 "data/Animation/Ch46/Dash.mv1", 0,  1.f},
        {"R2T I",        "data/Animation/Ch46/PreThrow Idle.mv1", 0,  1.f},
        {"R2T F", "data/Animation/Ch46/PreThrow Run Forward.mv1", 0,  1.f},
        {"R2T B",    "data/Animation/Ch46/PreThrow Run Back.mv1", 0,  1.f},
        {"R2T L",    "data/Animation/Ch46/PreThrow Run Left.mv1", 0,  1.f},
        {"R2T R",   "data/Animation/Ch46/PreThrow Run Right.mv1", 0,  1.f}
    } );

    // collision
    auto coll = AddComponent<ComponentCollisionCapsule>();
    coll->SetTranslate( float3( 0 ) );
    coll->SetRadius( 0.3f );
    coll->SetHeight( 1.5f );
    coll->UseGravity();

    // controller
    auto ctrl = AddComponent<PlayerController>();
    ctrl->SetSpeed( 0.02f );

    return true;
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Player::Update()
{
}

void Player::Draw()
{
}

void Player::Exit()
{
}

BP_COMPONENT_IMPL( PlayerController, u8"移動コンポーネント" );
void PlayerController::Init()
{
    Super::Init();
    this->player   = GetOwner();
    this->throwing = false;
    this->dashing  = false;
}

void PlayerController::PlayerUpdate()
{
    // count movement
    float3 dir( 0 );
    if( IsKey( key_up_ ) )
        dir.z += -1.f;

    if( IsKey( key_down_ ) )
        dir.z += +1.f;

    if( IsKey( key_right_ ) )
        dir.x += -1.f;

    if( IsKey( key_left_ ) )
        dir.x += +1.f;

    if( auto mdl = player->GetComponent<ComponentModel>() )
    {
        this->dashing     = IsMouse( MOUSE_INPUT_RIGHT );
        this->prethrowing = IsMouseRepeat( MOUSE_INPUT_LEFT );
        auto PlayLoop     = [&]( std::string_view anim_name ) {
            mdl->PlayAnimationNoSame( anim_name, true );
        };
        // dashing
        // play throwing animation
        if( dashing )
        {
            auto dir = normalize( -mdl->GetMatrix().axisZ() );
            player->AddTranslate( dir * speed_ * 4.f, true );
        }

        // is moving
        if( (f32)length( dir ) > 0.00f )
        {
            if( ! throwing )
            {
                dir = normalize( dir );
                // set movement
                player->AddTranslate( dir * speed_, true );

                // is prethrowing ?
                if( prethrowing )
                {
                    // back to forward diraction smoothly
                    mdl->SetRotationToVectorWithLimit( float3( float2( 0 ),
                                                               -1 ),
                                                       rot_speed_ );
                    // run to throw animation
                    // play LR first if input at the same time
                    PlayLoop( IsKey( key_right_ )  ? "R2T R"
                              : IsKey( key_left_ ) ? "R2T L"
                              : IsKey( key_down_ ) ? "R2T B"
                                                   : "R2T F" );
                }
                else
                {
                    // set model rotation
                    mdl->SetRotationToVectorWithLimit( dir, rot_speed_ );
                    // stander run animation
                    PlayLoop( dashing ? "dash" : "run" );
                }
            }
        }
        // not moving
        else
        {
            // play idle animation
            if( ! throwing )
            {
                // back to forward diraction smoothly
                mdl->SetRotationToVectorWithLimit( float3( float2( 0 ), -1 ),
                                                   rot_speed_ );
                PlayLoop( dashing ? "dash" : prethrowing ? "R2T I" : "idle" );
            }
        }
        // throwing
        {
            // check is throwing animation done
            if( throwing )
            {
                if( ! mdl->IsPlaying() || dashing )
                {
                    // throwing is done
                    throwing = false;
                }
            }
            // play throwing animation
            if( IsMouseUp( MOUSE_INPUT_LEFT ) )
            {
                throwing = true;
                mdl->PlayAnimationNoSame( "throw", false );
            }
        }
    }
}
void PlayerController::CameraUpdate()
{
    // camera
    if( auto arm = Scene::GetObjectPtr<Camera>( "PlayerCam" )
                       ->GetComponent<ComponentSpringArm>() )
    {
        auto obj = arm->GetSpringArmObject().lock();
        if( obj.get() == player )
        {
            if( auto target = target_.lock() )
            {

                player->SetRotationToPositionWithLimit( target->GetTranslate(),
                                                        target_cam_side_speed_ *
                                                            GetDeltaTime60() );

                cam_ry_ = player->GetRotationAxisXYZ().y;
                cam_rx_ = ( cam_rx_ + target_cam_up_down ) * 0.95f -
                          target_cam_up_down;

                arm->SetSpringArmRotate( { cam_rx_, 0, 0 } );
            }
            else
            {
                f32 const delta     = GetDeltaTime60();
                f32 const mouse_y   = mouse_up_down_ * delta;
                f32 const mouse_x   = mouse_left_right_ * delta;
                f32 const cam_speed = cam_speed_ * delta;
                // mouse control
                if( IsKeyOn( KEY_INPUT_P ) )
                    use_mouse_ = ! use_mouse_;
                if( use_mouse_ )
                {
                    // set mouse point unvisable
                    SetMouseDispFlag( FALSE );
                    // set mouse to center of window
                    SetMousePoint( WINDOW_CENTER.x, WINDOW_CENTER.y );
                    // mouse offset count
                    const float2 mouse_mov( GetMouseX() - WINDOW_CENTER.x,
                                            GetMouseY() - WINDOW_CENTER.y );

                    // rotate camera
                    cam_rx_ -= mouse_mov.y * ( mouse_y / 100.f );
                    cam_ry_ += mouse_mov.x * ( mouse_x / 100.f );
                    // limit camera rotation x
                    cam_rx_ =
                        std::clamp( cam_rx_, limit_cam_down_, limit_cam_up_ );
                    // limit camera rotation y
                    cam_ry_ = cam_ry_ < -360  ? cam_ry_ + 360
                              : cam_ry_ > 360 ? cam_ry_ - 360
                                              : cam_ry_;

                    // rotate player (cam_y)
                    player->SetRotationAxisXYZ( float3( 0, cam_ry_, 0 ) );
                    // rotate spring arm (cam_x)
                    arm->SetSpringArmRotate( float3( cam_rx_, float2( 0 ) ) );
                }
                else
                    SetMouseDispFlag( TRUE );
            }
        }
    }
}

void PlayerController::Dash()
{
}

void PlayerController::Update()
{
    PlayerUpdate();
    CameraUpdate();
}
