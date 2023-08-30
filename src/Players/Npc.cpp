#include <WinMain.h>
#include <Game/GameMain.h>
#include <System/Component/ComponentModel.h>
#include "Npc.h"

BP_OBJECT_IMPL( Npc, "Npc" );
NpcPtr Npc::Create( float3 pos )
{
    auto obj = Scene::CreateObjectPtr<Npc>();
    obj->SetName( "Akane" );
    obj->pos = pos;
    obj->SetTranslate( pos );
    return obj;
}

bool Npc::Init()
{
    if( ! Super::Init() )
        return false;
    auto mdl = AddComponent<ComponentModel>( "data/Model/angGirl.mv1" );

    mdl->SetAnimation( {
        {"throw", "data/Animation/Akane/Frisbee Throw.mv1", 0, 2.0f}
    } );

    return true;
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Npc::Update()
{
    if( auto mdl = GetComponent<ComponentModel>() )
    {
        if( mdl->GetPlayAnimationName() != "throw" )
            mdl->PlayAnimation( "throw", true );
    }
}

void Npc::Draw()
{
}

void Npc::Exit()
{
}
