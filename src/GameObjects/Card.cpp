#include "WinMain.h"
#include "Game/GameMain.h"
#include "Card.h"
#include <System/Component/ComponentModel.h>

BP_OBJECT_IMPL( Card, "Card" )
CardPtr Card::Create( CardParam param, float3 model_pos, float2 img_pos )
{
    // create object
    auto obj = Scene::CreateObjectDelayInitialize<Card>();
    if( ! obj )
        return obj;
    // set matrix body
    auto mat = matrix::identity();
    mat      = mul( mat, matrix::rotateX( D2R( 90.f ) ) );  //!< rotation
    mat      = mul( mat, matrix::rotateZ( D2R( 180.f ) ) );
    mat      = mul( mat, matrix::scale( f32( 0.1f ) ) );    //!< scale
    mat      = mul( mat, matrix::translate( model_pos ) );  //!< position
    obj->SetMatrix( mat );
    // load game param
    obj->param = param;
    // set object name
    string name = param.suit + std::to_string( param.value );
    obj->SetName( "Card" + name );
    // image
    obj->img_pos = img_pos;
    return obj;
}

bool Card::Init()
{
    if( ! Super::Init() )
        return false;
    // load model
    auto model = AddComponent<ComponentModel>();
    if( ! model )
        return false;
    // mv1 file
    {
        const string path = "data/Models/Cards/" + this->param.suit +
                            toString( this->param.value ) + ".mv1";
        model->Load( path );
    }
    // load materials
    {
        const string path = "data/Textures/CardsAndTables/CardsAndTables_";
        Material     matl{};
        matl.AO        = makeSptr<Texture>( path + "Mixed_AO.png" );
        matl.albedo    = makeSptr<Texture>( path + "Base_color.png" );
        matl.normal    = makeSptr<Texture>( path + "Normal_OpenGL.png" );
        matl.roughness = makeSptr<Texture>( path + "Roughness.png" );
        matl.metalness = makeSptr<Texture>( path + "Metallic.png" );
        materials.push_back( matl );
    }
    // set materials
    model->SetProc(
        "ModelDraw",
        [model, this]() {
            if( auto model_card = model->GetModelClass() )
            {
                auto& matl = this->materials[0];
                model_card->overrideTexture( Model::TextureType::Diffuse,
                                             matl.albedo );
                model_card->overrideTexture( Model::TextureType::AO, matl.AO );
                model_card->overrideTexture( Model::TextureType::Albedo,
                                             matl.albedo );
                model_card->overrideTexture( Model::TextureType::Normal,
                                             matl.normal );
                model_card->overrideTexture( Model::TextureType::Roughness,
                                             matl.roughness );
                model_card->overrideTexture( Model::TextureType::Metalness,
                                             matl.metalness );

                model_card->renderByMesh( 0 );
            }
        },
        ProcTiming::Draw );
    // load image
    this->front_Img = Image(
        IMGctrl.GetCardIMGdata( this->param.suit, this->param.value ) );
    this->back_Img = Image( IMGctrl.GetCardIMGdata( "Back" ) );

    return true;
}

void Card::Update()
{
    bool      is_player = this->img_pos.y > WINDOW_H / 2;
    const u32 offset( 200 );
    f32       size_h = this->front_Img.GetImgSize().y / 2;

    this->img_pos.y = is_select                      //
                          ? is_player                //!< true
                                ? WINDOW_H - offset  //!< true
                                : WINDOW_H + offset  //!< false
                                                     //
                          : is_touch                 //!< false
                                ? WINDOW_H - size_h  //!< true
                                : WINDOW_H;          //!< false

    switch( this->place )
    {
        case NONE_PLACE : break;
        case ON_PLAYER_BOARD : break;
        case IN_PLAYER_DECK : break;
        case IN_PLAYER_HAND : break;
        case ON_NPC_BOARD : break;
        case IN_NPC_DECK : break;
        case IN_NPC_HAND : break;
        default : break;
    }
}

void Card::LateDraw()
{
}

void Card::GUI()
{
    __super::GUI();
    ImGui::Begin( GetName().data() );
    {
        ImGui::Separator();
    }
    ImGui::End();
}

void Card::Exit()
{
}

void Card::RenderImg()
{
    DrawRotaGraph( img_pos.x,
                   img_pos.y,
                   1,
                   0,
                   is_show ? front_Img.GetImgHandle() : back_Img.GetImgHandle(),
                   true );
}

CardParam Card::GetCardParam() const
{
    return this->param;
}

bool Card::Flip()
{
    auto mat = matrix::identity();
    mat      = mul( mat, matrix::rotateY( D2R( 180.f ) ) );
    mat      = mul( mat, GetMatrix() );
    SetMatrix( mat );
    is_show = ! is_show;
    return is_show;
}

float2 Card::GetImgPos()
{
    return this->img_pos;
}

float2 Card::SetImgPos( float2 pos )
{
    this->img_pos = pos;
    return this->img_pos;
}
