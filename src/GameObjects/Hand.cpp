#include "WinMain.h"
#include "BaseClass/Base.h"
#include "Hand.h"
Hand::Hand( int image ) : Base( image )
{
    hand = std::make_unique<Cards>();
}

void Hand::Init()
{
}

void Hand::Update()
{
    for( auto& card: *hand )
        card->Update();
}

void Hand::Render( bool is_player )
{
    for( auto& card: *hand )
    {
        card->Render( is_player );
    }
}

void Hand::Release()
{
}

Cards Hand::Fold( Cards cards )
{
    return cards;
}

void Hand::Draw( Cards cards, bool is_player )
{
    u32 i        = 0;
    u32 card_num = (u32)( cards.size() );
    for( auto& card: cards )
    {
        u32 offset = 80;
        u32 x      = WINDOW_W / 2 + ( i - card_num / 2 ) * offset;
        u32 y      = is_player ? WINDOW_H : 0;
        card->pos  = Vector2( x, y );
        hand->push_back( card );
        i++;
    }
}

u32 Hand::GetHandNum() const
{
    return (u32)( hand->size() );
}

Cards Hand::GetHandCards() const
{
    return *hand;
}
