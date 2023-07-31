#include "WinMain.h"
#include "Hand.h"
Hand::Hand()
{
    this->hand.clear();
}

Hand::Hand( bool is_player )
{
    Hand();
    img_pos.x = f32( WINDOW_W * 0.5f );
    img_pos.y = f32( is_player       //!< the position of deck
                         ? WINDOW_H  //!< player
                         : 0 );      //!< npc
}

Hand::~Hand()
{
}

void Hand::Init()
{
}

void Hand::Update()
{
    u32 index = 0;
    for( auto& card: this->hand )
    {
        // model
        {
            auto mat = matrix::identity();
        }
        // image
        {
            f32 offset( 80.f );
            f32 x( img_pos.x + ( index - hand.size() / 2 ) * offset );
            f32 y( img_pos.y );
            card->SetImgPos( float2( x, y ) );
        }
        index++;
    }
}

void Hand::RenderImg()
{
    for( auto& card: hand )
    {
        card->RenderImg();
    }
}

void Hand::Release()
{
}

Cards Hand::Fold( Cards cards )
{
    for( auto& card: cards )
    {
        Cards::iterator it = std::find( hand.begin(), hand.end(), card );
        hand.erase( it );
    }
    return cards;
}

void Hand::Draw( Cards cards )
{
    for( auto& card: cards )
    {
        hand.push_back( card );
    }
}

u32 Hand::GetHandNum() const
{
    return (u32)( hand.size() );
}

Cards Hand::GetHandCards() const
{
    return hand;
}
