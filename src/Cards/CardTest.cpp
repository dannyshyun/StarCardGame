#include <System/Component/ComponentModel.h>
#include "WinMain.h"
#include "Game/GameMain.h"
#include "BaseClass/Base.h"
#include "CardTest.h"

BP_OBJECT_IMPL( CardTest, "CardTest" );
CardTestPtr
    CardTest::Create( CardParam param, float3 model_pos, float2 img_pos )
{
    // 3d
    auto card = Scene::CreateObjectDelayInitialize<CardTest>();
    auto mat  = HelperLib::Math::CreateMatrixByFrontVector( float3( 0, -1, 0 ),
                                                           float3( 0, 0, 1 ) );
    card->SetMatrix( mat );
    card->param      = param;
    std::string name = param.suit + std::to_string( param.value );
    card->SetName( "Card" + name );
    card->SetTranslate( model_pos );
    card->SetScaleAxisXYZ( f32( 0.1f ) );
    // 2d
    card->frontImg = Image( IMGctrl.GetCardIMGdata( param.suit, param.value ) );
    card->backImg  = Image( IMGctrl.GetCardIMGdata( "Back" ) );
    card->img_pos  = img_pos;
    return card;
}

bool CardTest::Init()
{
    __super::Init();

    if( auto model = AddComponent<ComponentModel>() )
    {
        // load model
        {
            const std::string path = "data/Models/Cards/" + param.suit +
                                     std::to_string( param.value ) + ".mv1";
            model->Load( path );
        }
        // material
        {
            const std::string path =
                "data/Textures/CardsAndTables/CardsAndTables_";
            Material mat{};
            mat.AO        = makeSptr<Texture>( path + "Mixed_AO.png" );
            mat.albedo    = makeSptr<Texture>( path + "Base_color.png" );
            mat.normal    = makeSptr<Texture>( path + "Normal_OpenGL.png" );
            mat.roughness = makeSptr<Texture>( path + "Roughness.png" );
            mat.metalness = makeSptr<Texture>( path + "Metallic.png" );
            materials.push_back( mat );
        }
        model->SetProc(
            "ModelDraw",
            [model, this]() {
                if( auto model_card = model->GetModelClass() )
                {
                    auto& mat = materials[0];
                    model_card->overrideTexture( Model::TextureType::Diffuse,
                                                 mat.albedo );
                    model_card->overrideTexture( Model::TextureType::AO,
                                                 mat.AO );
                    model_card->overrideTexture( Model::TextureType::Albedo,
                                                 mat.albedo );
                    model_card->overrideTexture( Model::TextureType::Normal,
                                                 mat.normal );
                    model_card->overrideTexture( Model::TextureType::Roughness,
                                                 mat.roughness );
                    model_card->overrideTexture( Model::TextureType::Metalness,
                                                 mat.metalness );

                    model_card->renderByMesh( 0 );
                }
            },
            ProcTiming::Draw );
    }

    return true;
}

void CardTest::Update()
{
    if( IsKeyRepeat( KEY_INPUT_Z ) )
    {
        const auto mat_body = GetMatrix();
        auto       mat      = matrix::identity();
        static f32 degree_y( 0.f );
        degree_y += 1.f;
        mat = mul( mat, matrix::rotateY( D2R( degree_y ) ) );
        mat = mul( mat, mat_body );
        SetMatrix( mat );
    }
}

void CardTest::RenderImg()
{
    DrawRotaGraphF( img_pos.x,
                    img_pos.y,
                    1,
                    0,
                    is_show ? frontImg.handle : backImg.handle,
                    true );
}

void CardTest::LateDraw()
{
}

void CardTest::GUI()
{
    __super::GUI();
    ImGui::Begin( GetName().data() );
    {
        ImGui::Separator();
    }
    ImGui::End();
}

void CardTest::Exit()
{
}

CardParam CardTest::GetCardParam() const
{
    return this->param;
}

bool CardTest::Flip()
{
    is_show = ! is_show;
    return is_show;
}

bool CardTest::IsShow() const
{
    return is_show;
}
