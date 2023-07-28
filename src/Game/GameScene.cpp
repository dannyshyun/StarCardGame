#include <System/Scene.h>
#include "GameMain.h"
#include "GameScene.h"
#include "Cards/CardTest.h"
#include "GameObjects/Table.h"
#include "GameObjects/Dice.h"
#include "Cameras/CameraBase.h"

#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCamera.h>

#include "System/Component/ComponentCollisionModel.h"

namespace MainScene
{
    namespace Scene3D
    {
        BP_CLASS_IMPL( TestScene, u8"Test" );
        bool TestScene::Init()
        {
            IMGctrl.Init();
            // // ground
            // {
            //     auto obj = Scene::CreateObjectPtr<Object>()->SetName( "Ground" );
            //     obj->AddComponent<ComponentModel>(
            //         "data/Sample/SwordBout/Stage/Stage00.mv1" );
            //     obj->SetScaleAxisXYZ( f32( 0.1f ) );
            //     auto col = obj->AddComponent<ComponentCollisionModel>();
            //     col->AttachToModel( true );
            // }
            // table
            {
                auto table = Table::Create()->SetName( "Table" );
            }

            // card
            {
                auto card = CardTest::Create( CardParam( "Sword", 2 ),
                                              float3( 0.f, 1.3f, 0.f ),
                                              float2( WINDOW_W / 2, WINDOW_H / 2 ) );
            }
            // dice
            {
                // auto dice0 = Dice::Create( "Red" );
                // auto dice1 = Dice::Create( "Blue", float3( 0, 1.3f, 0 ) );
            }  // camera
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
            //Turn = LOAD_TURN;
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
            // todo
            if( Scene::GetObjectPtr<Object>("PlayCamera"))
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
