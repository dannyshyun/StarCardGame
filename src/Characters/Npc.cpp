#include <WinMain.h>
#include <Game/GameMain.h>
#include <GameSystem/Random.h>
#include <BaseClass/Base.h>
#include "Player.h"
#include "Npc.h"

Npc::Npc( int image ) : Player( image )
{
    deck = std::make_unique<Deck>( 0 );
    hand = std::make_unique<Hand>( 0 );
}
//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Npc::Init()
{
    deck->Init();
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
                hand->Draw( deck->Deal( HAND_MAX - hand->GetHandNum() ),
                            false );
            }
            break;
    }
    deck->Update();
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Npc::Render()
{
    deck->Render( false );
    hand->Render( false );
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Npc::Release()
{
}

void Npc::SelectCard( CardBase card )
{
}
