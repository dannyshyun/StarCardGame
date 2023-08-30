#include <System/Scene.h>
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionModel.h>
#include <System/Component/ComponentCamera.h>
#include <System/Component/ComponentAttachModel.h>
#include "GameMain.h"
#include "GameScene.h"
#include "Players/Player.h"
#include "Players/Npc.h"
#include "GameObjects/Frisbee.h"
#include "Camera/Camera.h"

namespace MainScene
{

    BP_CLASS_IMPL( TestScene, u8"Test" );
    bool TestScene::Init()
    {
        if( ! Super::Init() )
            return false;

        // ground
        auto ground = Scene::CreateObjectPtr<Object>()->SetName( "Ground" );
        ground->AddComponent<ComponentModel>( "data/Model/ground.mqoz" );
        ground->SetScaleAxisXYZ( float3( 5 ) );
        if( auto mdl = ground->AddComponent<ComponentCollisionModel>() )
        {
            mdl->AttachToModel( true );
        }
        // player

        auto player = Player::Create();

        // frisbee

        auto frisbee = Frisbee::Create();
        if( auto attach = frisbee->AddComponent<ComponentAttachModel>() )
        {
            attach->SetAttachObject( player, "mixamorig:RightHand" );
            attach->SetAttachRotate( { 0, -60, 180 } );
            // attach->SetAttachOffset({13, 10, 5});
        }

        // camera
        if( auto obj = Scene::CreateObjectPtr<Object>() )
        {
            obj->SetName( "DefaultCam" );
            auto cam = obj->AddComponent<ComponentCamera>();
            cam->SetPositionAndTarget( float3( 0, 4, -4 ), float3( 0 ) );
            cam->SetCurrentCamera();
        }

        // player camera
        auto p_cam = Camera::Create( player );
        p_cam->SetName( "PlayerCam" );

        return true;
    }
    void TestScene::Update()
    {
        if( IsKeyOn( KEY_INPUT_1 ) )
            Scene::SetCurrentCamera( "PlayerCam" );
        if( IsKeyOn( KEY_INPUT_2 ) )
            Scene::SetCurrentCamera( "DefaultCam" );
    }

    void TestScene::Draw()
    {
    }

    void TestScene::LateDraw()
    {
    }

    void TestScene::Exit()
    {
    }

    void TestScene::GUI()
    {
    }

}
