#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionModel.h>
#include "WinMain.h"
#include "Game/GameMain.h"
#include "BaseClass/Base.h"
#include "Table.h"

BP_OBJECT_IMPL( Table, "Table" );
TablePtr Table::Create( float3 pos )
{
    auto table = Scene::CreateObjectPtr<Table>();
    table->SetName( "Table" );
    table->SetTranslate( pos );
    table->SetScaleAxisXYZ( f32( 0.1f ) );
    return table;
}

bool Table::Init()
{
    if( ! __super::Init() )
        return false;

    if( auto model = AddComponent<ComponentModel>() )
    {
        model->Load( "data/Models/Table/Table.mv1" );
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
    // table collision
    {
        auto col = AddComponent<ComponentCollisionModel>();
        col->AttachToModel();
        col->SetCollisionGroup( ComponentCollisionModel::CollisionGroup::WALL );
    }

    return true;
}

void Table::Update()
{
}

void Table::Render()
{
}

void Table::GUI()
{
    __super::GUI();
    ImGui::Begin( GetName().data() );
    {
        ImGui::Separator();
    }
    ImGui::End();
}

void Table::Exit()
{
}
