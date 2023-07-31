#include "WinMain.h"
#include "Game/GameMain.h"
#include "Deck.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <utility>

using json = nlohmann::json;

Deck::Deck()
{
    // get IMG data from UI container
    this->img = IMGctrl.GetUIIMGdata( "deck" );
    this->deck.clear();
    Shuffle();
}

Deck::Deck( bool is_player )
{
    Deck();
    mdl_pos.x = f32( -0.2f );
    mdl_pos.y = f32( 1.3f );
    mdl_pos.z = f32( 0.f );
    img_pos.x = f32( 60.f );
    img_pos.y = f32( is_player            //!< the position of deck
                         ? WINDOW_H - 40  //!< player
                         : 40 );          //!< npc
}

Deck::~Deck()
{
}

void Deck::Init()
{
}

bool Deck::Load()
{
    std::ifstream file( "data/deckData.json" );
    json          jfile = json::parse( file );
    // parse json object
    for( auto& obj: jfile )
    {
        std::string suit  = obj["suit"];
        u32         value = obj["value"];
        u32         num   = obj["num"];
        CardParam   param( suit, value );
        // insert the card * num times
        for( u32 i = 0; i < num; i++ )
        {
            auto card     = Card::Create( param, mdl_pos, img_pos );
            card->is_show = false;
            this->deck.push_back( card );
        }
    }
    // return true when loading is done
    if( this->num < this->deck.size() )
    {
        this->num++;
        return false;
    }
    return true;
}
void Deck::Update()
{
    // set card position
    for( auto& card: this->deck )
    {
        // model
        {
            auto mat = matrix::identity();
            mat      = mul( mat, matrix::translate( this->mdl_pos ) );
            mat      = mul( mat, card->GetMatrix() );
            card->SetMatrix( mat );
        }
        // image
        {
            card->SetImgPos( this->img_pos );
        }
    }
    if( Turn != LOAD_TURN )
        // show card num in deck immediately
        num = (u32)( deck.size() );
}

void Deck::RenderImg()
{
    // font type
    ChangeFontType( DX_FONTTYPE_EDGE );
    // render image
    DrawRotaGraphF( img_pos.x,
                    img_pos.y,
                    1,
                    0,
                    this->img.GetImgHandle(),
                    true );
    // render num
    DrawFormatStringF( img_pos.x + 25.f,
                       img_pos.y - 10.f,
                       WHITE,
                       ( TC ) "%2d",
                       this->num );
}

void Deck::Release()
{
}

u32 Deck::GetNum() const
{
    return this->num;
}

void Deck::Revoke( Cards cards )
{
    for( auto& card: cards )
    {
        // insert to the deck
        deck.push_back( card );
    }
}

bool Deck::Shuffle()
{
    // return true when shuffling is done
    bool done = false;
    for( auto& card: this->deck )
    {
        // index of container to swap
        u32 rand = GetRand( u32( deck.size() ) - 1 );
        std::swap( card, *( deck.begin() + rand ) );
    }
    done = true;
    return done;
}

Cards Deck::Deal( u32 num )
{
    // no card could be returned
    if( deck.empty() )
    {
        return Cards();
    }
    // less than num cards could be returned
    else if( deck.size() < num )
    {
        Cards temp( deck.begin(), deck.end() );
        Cards().swap( deck );
        return temp;
    }
    // return num cards
    else
    {
        Cards temp( deck.begin(), deck.begin() + num );
        deck.erase( deck.begin(), deck.begin() + num );
        return temp;
    }
}
