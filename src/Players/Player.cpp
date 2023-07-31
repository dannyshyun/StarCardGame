#include <WinMain.h>
#include <Game/GameMain.h>
#include "Player.h"

BP_OBJECT_IMPL( Player, "Player" );
PlayerPtr Player::Create()
{
    auto obj  = Scene::CreateObjectPtr<Player>();
    obj->mdl_pos = float3( -0.6f, 1.3f, 0 );
    obj->img_pos = float2( 0, WINDOW_H - 40 );
    obj->deck    = makeSptr<Deck>( true );
    obj->hand = makeSptr<Hand>( true );
    return obj;
}

bool Player::Init()
{
    if( ! Super::Init() )
        return false;

    return true;
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
                hand->Draw( deck->Deal( HAND_MAX - hand->GetHandNum() ) );
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

void Player::Exit()
{
}

void Player::RenderImg()
{
    deck->RenderImg();
    hand->RenderImg();
}

void Player::SelectCard( CardPtr card )
{
    if( card->is_touch )
        card->is_select = ! card->is_select;
}

void Player::CheckTouch( CardPtr card )
{
    float2 mouse_pos( GetMouseX(), GetMouseY() );
    // check mouse in screen
    if( mouse_pos.x < 0 || mouse_pos.x > WINDOW_W || mouse_pos.y < 0 ||
        mouse_pos.y > WINDOW_H )
        return;
    // check mouse in touchable card area
    card->is_touch =
        ( mouse_pos.x <=
              ( card->GetImgPos().x + IMGctrl.GetCardSize().x * 0.5f ) &&
          mouse_pos.x >=
              ( card->GetImgPos().x - IMGctrl.GetCardSize().x * 0.5f ) &&
          mouse_pos.y <=
              ( card->GetImgPos().y + IMGctrl.GetCardSize().y * 0.5f ) &&
          mouse_pos.y >=
              ( card->GetImgPos().y - IMGctrl.GetCardSize().y * 0.5f ) );
}
