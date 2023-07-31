#include <System/Scene.h>
#include "GameMain.h"
#include "GameScene.h"
#include "GameObjects/Table.h"
#include "GameObjects/Dice.h"
#include "Cameras/CameraBase.h"

#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCamera.h>
#include "System/Component/ComponentCollisionModel.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
namespace MainScene
{
    namespace Scene3D
    {
        BP_CLASS_IMPL( TestScene, u8"Test" );
        bool TestScene::Init()
        {
            IMGctrl.Init();
            // table
            {
                auto table = Table::Create()->SetName( "Table" );
            }
            // player
            {
                // auto player = Player::Create()->SetName( "Player" );
            }  
            // test
            {
                std::ifstream file( "data/deckData.json" );
                json          jfile = json::parse( file );
                // parse json object
                for( auto& obj: jfile )
                {
                    std::string suit  = obj["suit"];
                    u32         value = obj["value"];
                    u32         num   = obj["num"];
                    CardParam   param( suit, value );
                    // insert the card * num times
                    for( u32 i = 0; i < num; i++ )
                    {
                        auto card     = Card::Create( param, float3(0,1.3f,0), float2(200,600) );
                        card->is_show = false;
                    }
                }
            }
            // camera
            {
                float3 pos( 0, 37.5f, 40.3f );
                float3 target( 0, 0.8f, -0.5f );
                auto   cam =
                    CameraBase::Create( pos, target )->SetName( "PlayCamera" );
                cam->SetRotationAxisXYZ( float3( 0, 180, 0 ) );
            }
            // camera
            {
                auto   table = Scene::GetObjectPtr<Object>( "Table" );
                float3 pos( 0, 80, 0.1f );
                float3 target( table->GetTranslate() );
                auto   cam =
                    CameraBase::Create( pos, target )->SetName( "TopCamera" );
                cam->SetRotationAxisXYZ( float3( 0, 180, 0 ) );
            }
            Turn = LOAD_TURN;
            // npc->Init();
            // player->Init();
            return true;
        }
        void TestScene::Update()
        {
            if( IsKeyOn( KEY_INPUT_1 ) )
                Scene::SetCurrentCamera( "TopCamera" );

            if( IsKeyOn( KEY_INPUT_2 ) )
                Scene::SetCurrentCamera( "PlayCamera" );

            counter++;
            // npc->Update();
            // player->Update();
        }

        void TestScene::Draw()
        {

            auto card = Scene::GetObjectPtr<Object>( "CardSword2" );
            if( auto obj = Scene::PickObject( GetMouseX(), GetMouseY() ) )
            {
                DrawString( 16,
                            16,
                            TC( std::string( obj->GetName() ).c_str() ),
                            WHITE );
            }
            // todo
        }

        void TestScene::LateDraw()
        {
            if( auto cam = Scene::GetCurrentCamera().lock() )
            {
                if( cam->GetOwner()->GetName() == "TopCamera" )
                {
                    // auto player = GetObjectPtr<Player>( "Player" );
                    // player->RenderImg();
                }
            }
        }

        void TestScene::Exit()
        {
        }

        void TestScene::GUI()
        {
            ImGui::InputInt( "Counter", &counter );
            // npc->Render();
            // player->Render();
            // ui->Render();
        }
    }
    namespace Scene2D
    {

    }
}
