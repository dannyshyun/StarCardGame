#include <BaseClass/Base.h>
#include <Cards/CardBase.h>
#include "ItemCard.h"
#include "HpPlusCard.h"

HpPlusCard::HpPlusCard( int image, u32 value, u32 part ) :
    ItemCard( image, value, part )
{
}
void HpPlusCard::Init()
{
    ItemCard::Init();
}

void HpPlusCard::Update()
{
    ItemCard::Update();
}

void HpPlusCard::Render( bool is_show )
{
    ItemCard::Render( is_show );
}

void HpPlusCard::Release()
{
    ItemCard::Release();
}
