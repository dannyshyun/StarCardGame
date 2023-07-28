#include <BaseClass/Base.h>
#include <Cards/CardBase.h>
#include "ItemCard.h"
#include "CurseCard.h"
CurseCard::CurseCard( int image, u32 value, u32 part ) :
    ItemCard( image, value, part )
{
}
void CurseCard::Init()
{
    ItemCard::Init();
}

void CurseCard::Update()
{
    ItemCard::Update();
}

void CurseCard::Render( bool is_show )
{
    ItemCard::Render( is_show );
}

void CurseCard::Release()
{
    ItemCard::Release();
}
