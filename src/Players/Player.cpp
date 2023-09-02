#include <WinMain.h>
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionCapsule.h>
#include "Camera/Camera.h"
#include "GameObjects/Frisbee.h"
#include "PlayerController.h"
#include "Player.h"

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
    if( auto coll = AddComponent<ComponentCollisionCapsule>() )
    {
        coll->SetTranslate( float3( 0 ) );
        coll->SetRadius( 0.3f );
        coll->SetHeight( 1.5f );
        coll->UseGravity();
    }

    // controller
    if( auto ctrl = AddComponent<PlayerController>() )
    {
        ctrl->SetSpeed( 0.02f );
    }

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
