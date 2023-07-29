#pragma once
#include <System/Scene.h>
#include "UI/Image.h"

enum StarPart
{
    STAR_HEAD = 0,
    STAR_RIGHT_HAND,
    STAR_LEFT_HAND,
    STAR_RIGHT_LEG,
    STAR_LEFT_LEG,

    STAR_NUM_MAX
};

struct CardParam
{
public:
    CardParam() : value( 0 ){};
    CardParam( const std::string& suit, u32 value )
    {
        this->suit  = std::move( suit );
        this->value = value;
    };

public:
    std::string suit;
    u32         value{ 0 };
};

USING_PTR( CardBase );
class CardBase : public Object
{
public:
    // create
    BP_OBJECT_TYPE( CardTest, Object );
    static CardTestPtr Create( CardParam param,
                               float3    model_pos = { 0.f, 0.f, 0.f },
                               float2    img_pos   = { 0.f, 0.f } );
    // auto run
    virtual bool Init() override;
    virtual void Update() override;
    virtual void LateDraw() override;
    virtual void GUI() override;
    virtual void Exit() override;
    // callable function
    virtual void RenderImg();
    // get
    virtual u32  GetCardParam() const;
    virtual bool IsShow() const;
    // set
    virtual bool Flip();

protected:
    // game paramenter
    CardParam param{};
    // image data
    Image frontImg;
    Image backImg;
    // model data
    bool  is_touch  = false;
    bool is_select = false;
};
template<class T> using Card = std::shared_ptr<T>;
typedef std::vector<std::shared_ptr<CardBase>> Cards;
typedef std::unique_ptr<Cards>                 ptr_cards;
