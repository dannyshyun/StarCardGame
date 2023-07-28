#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollision.h>
#include <System/Component/ComponentCollisionModel.h>
#include "WinMain.h"
#include "Game/GameMain.h"
#include "Dice.h"

BP_OBJECT_IMPL( Dice, "Dice" );
DicePtr Dice::Create( std::string color, float3 pos )
{
    auto dice   = Scene::CreateObjectDelayInitialize<Dice>();
    dice->color = color;
    dice->SetName( color + "Dice" );
    dice->SetTranslate( pos );
    dice->SetScaleAxisXYZ( f32( 0.1f ) );
    return dice;
}

bool Dice::Init()
{
    if( ! __super::Init() )
        return false;

    if( auto model = AddComponent<ComponentModel>() )
    {
        // model
        {
            const std::string path = "data/Models/Dices/Dice" + color + ".mv1";
            model->Load( path );
        }
        // material
        {
            const std::string path = "data/Textures/GamePieces/GamePieces_";
            Material          mat{};
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
    // dice collision
    {
        auto col = AddComponent<ComponentCollisionModel>();
        col->AttachToModel( true );
        col->SetCollisionGroup( ComponentCollisionModel::CollisionGroup::ITEM );
        //col->UseGravity();
    }

    return true;
}

void Dice::Update()
{
}

void Dice::Render()
{
}

void Dice::GUI()
{
    __super::GUI();
    ImGui::Begin( GetName().data() );
    {
        ImGui::Separator();
    }
    ImGui::End();
}

void Dice::Exit()
{
}

CEREAL_REGISTER_TYPE( Dice );
CEREAL_REGISTER_POLYMORPHIC_RELATION( Object, Dice );