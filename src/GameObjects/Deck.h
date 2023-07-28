#pragma once
#include "Cards/CardBase.h"
#include "Cards/Action/ActionCard.h"
#include "Cards/Item/ItemCard.h"
#include "Cards/Item/ChanceCard.h"
#include "Cards/Item/CurseCard.h"
#include "Cards/Item/HpPlusCard.h"

class Deck : public Base
{
public:
    Deck( int image );
    ~Deck();
    void Init() override;
    void Update() override;
    void Render( bool is_player );
    void Release() override;

    // revoke cards which are folded
    void Revoke( Cards cards );
    // load turn
    bool Load();
    // shuffle turn
    bool Shuffle();

    // deal cards from deck
    Cards Deal( u32 num );
    // get card num from deck
    u32 GetCardNum() const;

private:
    Card<ActionCard> NewActionCard( std::string suit, u32 value );
    Card<ChanceCard> NewChanceCard( std::string suit, u32 value );
    Card<HpPlusCard> NewHpPlusCard( std::string suit, u32 value );
    Card<CurseCard>  NewCurseCard( std::string suit, u32 value );
    void             LoadCardsIMG();
    // card container
    ptr_cards deck;
    // the number of card to render
    u32 card_num;
};
