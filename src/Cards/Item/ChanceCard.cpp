#include <BaseClass/Base.h>
#include <Cards/CardBase.h>
#include "ItemCard.h"
#include "ChanceCard.h"

ChanceCard::ChanceCard( int image, u32 value, u32 part ) :
    ItemCard( image, value, part )
{
}
void ChanceCard::Init()
{
    ItemCard::Init();
}

void ChanceCard::Update()
{
    ItemCard::Update();
}

void ChanceCard::Render( bool is_show )
{
    ItemCard::Render( is_show );
}

void ChanceCard::Release()
{
    ItemCard::Release();
}
