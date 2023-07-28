#pragma once

#include "BaseClass/Base.h"

enum StarPart
{
    STAR_HEAD = 0,
    STAR_RIGHT_HAND,
    STAR_LEFT_HAND,
    STAR_RIGHT_LEG,
    STAR_LEFT_LEG,

    STAR_NUM_MAX
};

class CardBase : public Base
{
public:
    CardBase( int image, u32 value, u32 part );
    ~CardBase();
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render( bool is_show );
    virtual void Release() override;
    virtual u32  GetCardVal() const;
    virtual u32  GetImage() const;

    bool is_select = false;
    bool is_touch  = false;

protected:
    u32 value = 0;
    u32 part  = 0;
};
template<class T> using Card = std::shared_ptr<T>;
typedef std::vector<std::shared_ptr<CardBase>> Cards;
typedef std::unique_ptr<Cards>                 ptr_cards;
