#include "WinMain.h"
#include "Game/GameMain.h"
#include "BaseClass/Base.h"
#include "Deck.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <utility>

using json = nlohmann::json;

Deck::Deck( int image ) : Base( image )
{
    // new pointer
    deck = std::make_unique<Cards>();
}

Deck::~Deck()
{
}

void Deck::Init()
{
    // get IMG data from UI container
    this->image    = IMGctrl.GetUIIMGdata( "deck" );
    this->card_num = 0;
    LoadCardsIMG();
    Shuffle();
}

void Deck::Update()
{
    if( Turn != LOAD_TURN )
        // show card num in deck immediately
        card_num = (u32)( deck->size() );
}

void Deck::Render( bool is_player )
{
    u32 y = is_player            //!< the position of deck
                ? WINDOW_H - 40  //!< player
                : 40;            //!< npc
    // font type
    ChangeFontType( DX_FONTTYPE_EDGE );
    // render image
    DrawRotaGraph( 60, y, 1, 0, image, true );
    // render num
    DrawFormatString( 85, y - 10, WHITE, ( TC ) "%2d", card_num );
}

void Deck::Release()
{
}

u32 Deck::GetCardNum() const
{
    return card_num;
}

void Deck::Revoke( Cards cards )
{
    for( auto& card: cards )
    {
        // insert to the deck
        deck->push_back( card );
    }
}

bool Deck::Load()
{
    // return true when loading is done
    if( card_num < deck->size() )
    {
        card_num++;
        return false;
    }
    return true;
}

bool Deck::Shuffle()
{
    // return true when shuffling is done
    bool done = false;
    for( auto& card: *deck )
    {
        // index of container to swap
        u32 rand = GetRand( u32( deck->size() ) - 1 );
        std::swap( card, *( deck->begin() + rand ) );
    }
    done = true;
    return done;
}

Cards Deck::Deal( u32 num )
{
    // no card could be returned
    if( deck->empty() )
    {
        return Cards();
    }
    // less than num cards could be returned
    else if( deck->size() < num )
    {
        Cards temp( deck->begin(), deck->end() );
        Cards().swap( *deck );
        return temp;
    }
    // return num cards
    else
    {
        Cards temp( deck->begin(), deck->begin() + num );
        deck->erase( deck->begin(), deck->begin() + num );
        return temp;
    }
}
Card<ActionCard> Deck::NewActionCard( std::string suit, u32 value )
{
    return std::make_shared<ActionCard>( IMGctrl.GetCardIMGdata( suit, value ),
                                         value,
                                         0,
                                         suit );
}

Card<ChanceCard> Deck::NewChanceCard( std::string suit, u32 value )
{
    return std::make_shared<ChanceCard>( IMGctrl.GetCardIMGdata( suit, value ),
                                         value,
                                         0 );
}

Card<HpPlusCard> Deck::NewHpPlusCard( std::string suit, u32 value )
{
    return std::make_shared<HpPlusCard>( IMGctrl.GetCardIMGdata( suit, value ),
                                         value,
                                         0 );
}

Card<CurseCard> Deck::NewCurseCard( std::string suit, u32 value )
{
    return std::make_shared<CurseCard>( IMGctrl.GetCardIMGdata( suit, value ),
                                        value,
                                        0 );
}

void Deck::LoadCardsIMG()
{
    // load json file
    std::ifstream file( "data/deckData.json" );
    json          jfile = json::parse( file );
    // parse json object
    for( auto& obj: jfile )
    {
        std::string suit  = obj["suit"];
        u32         value = obj["value"];
        u32         num   = obj["num"];
        // insert the card * num times
        for( u32 i = 0; i < num; i++ )
        {
            // check suit and new class
            ( suit == "sword" || suit == "gun" || suit == "shield" ||
              suit == "move" || suit == "star" )
                ? deck->push_back( NewActionCard( suit, value ) )
            : suit == "chance" ? deck->push_back( NewChanceCard( suit, value ) )
            : suit == "curse"  ? deck->push_back( NewCurseCard( suit, value ) )
            : suit == "hpPlus" ? deck->push_back( NewHpPlusCard( suit, value ) )
                               : deck->push_back( nullptr );
        }
    }
}
