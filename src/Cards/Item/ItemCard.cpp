#include <BaseClass/Base.h>
#include <Cards/CardBase.h>
#include "ItemCard.h"

ItemCard::ItemCard( int image, u32 value, u32 part ) :
    CardBase( image, value, part )
{
}
void ItemCard::Init()
{
    CardBase::Init();
}

void ItemCard::Update()
{
    CardBase::Update();
}

void ItemCard::Render( bool is_show )
{
    CardBase::Render( is_show );
}

void ItemCard::Release()
{
    CardBase::Release();
}
