#include <BaseClass/Base.h>
#include <Cards/CardBase.h>
#include "ActionCard.h"

ActionCard::ActionCard( int image, u32 value, u32 part, std::string suit ) :
    CardBase( image, value, part ), suit( suit )
{
}

ActionCard::~ActionCard()
{
}

void ActionCard::Init()
{
    CardBase::Init();
}

void ActionCard::Update()
{
    CardBase::Update();
}

void ActionCard::Render( bool is_show )
{
    CardBase::Render( is_show );
}

void ActionCard::Release()
{
    CardBase::Release();
}

std::string ActionCard::GetSuit() const
{
    return suit;
}
