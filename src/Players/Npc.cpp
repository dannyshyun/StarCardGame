#include <WinMain.h>
#include <Game/GameMain.h>
#include "Npc.h"

BP_OBJECT_IMPL( Npc, "Npc" );
NpcPtr Npc::Create()
{
    auto obj  = Scene::CreateObjectPtr<Npc>();
    obj->deck = makeSptr<Deck>( false );
    obj->hand = makeSptr<Hand>( false );
    return obj;
}
//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
bool Npc::Init()
{
    if( ! Super::Init() )
        return false;

    return true;
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Npc::Update()
{
    switch( Turn )
    {
        case LOAD_TURN : deck->Load(); break;

        case SHUFFLE_TURN : deck->Shuffle(); break;

        case DEAL_TURN :

            if( hand->GetHandNum() < HAND_MAX )
            {
                hand->Init();
                hand->Draw( deck->Deal( HAND_MAX - hand->GetHandNum() ) );
            }
            break;
    }
    deck->Update();
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Npc::RenderImg()
{
    deck->RenderImg();
    hand->RenderImg();
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Npc::Exit()
{
}

void Npc::SelectCard( CardPtr card )
{
}
