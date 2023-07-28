#include <WinMain.h>
#include <Game/GameMain.h>
#include <BaseClass/Base.h>
#include "Player.h"

Player::Player( int image ) : Base( image )
{
    deck = std::make_unique<Deck>( 0 );
    hand = std::make_unique<Hand>( 0 );
}
//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Player::Init()
{
    deck->Init();
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Player::Update()
{

    switch( Turn )
    {
        case LOAD_TURN :
            if( deck->Load() )
                Turn = SHUFFLE_TURN;
            break;

        case SHUFFLE_TURN :
            if( deck->Shuffle() )
                Turn = DEAL_TURN;
            break;

        case DEAL_TURN :

            if( hand->GetHandNum() < HAND_MAX )
            {
                hand->Init();
                hand->Draw( deck->Deal( HAND_MAX - hand->GetHandNum() ), true );
            }
            Turn = MOVE_TURN;
            break;

        case MOVE_TURN :
            for( auto& card: hand->GetHandCards() )
            {
                CheckTouch( card );
                if( IsMouseOn( MOUSE_INPUT_LEFT ) )
                    SelectCard( card );
            }
            break;

        case PLAYER_ATTACK_TURN :
            for( auto& card: hand->GetHandCards() )
            {
                CheckTouch( card );
            }
            break;

        case PLAYER_DEFENSE_TURN :
            for( auto& card: hand->GetHandCards() )
            {
                CheckTouch( card );
            }
            break;

        case NPC_ATTACK_TURN : break;

        case NPC_DEFESE_TURN : break;

        case RESULT_TURN : break;

        case TURN_MAX : break;

        default :;
    }
    deck->Update();
    hand->Update();
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Player::Render()
{
    deck->Render( true );
    hand->Render( true );
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Player::Release()
{
}

void Player::SelectCard( std::shared_ptr<CardBase> card )
{
    if( card->is_touch )
        card->is_select = ! card->is_select;
}

void Player::CheckTouch( std::shared_ptr<CardBase> card )
{
    Vector2 mouse_pos( GetMouseX(), GetMouseY() );
    // check mouse in screen
    if( mouse_pos.x < 0 || mouse_pos.x > WINDOW_W || mouse_pos.y < 0 ||
        mouse_pos.y > WINDOW_H )
        return;
    // check mouse in touchable card area
    card->is_touch = ( mouse_pos.x <= ( card->pos.x + card->size.x * 0.5 ) &&
                       mouse_pos.x >= ( card->pos.x - card->size.x * 0.5 ) &&
                       mouse_pos.y <= ( card->pos.y + card->size.y * 0.5 ) &&
                       mouse_pos.y >= ( card->pos.y - card->size.y * 0.5 ) );
}
