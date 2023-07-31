#pragma once
#include <System/Scene.h>

enum StarPart
{
    STAR_HEAD = 0,
    STAR_RIGHT_HAND,
    STAR_LEFT_HAND,
    STAR_RIGHT_LEG,
    STAR_LEFT_LEG,

    STAR_NUM_MAX
};

enum CardPlace
{
    NONE_PLACE = 0,
    ON_PLAYER_BOARD,
    IN_PLAYER_DECK,
    IN_PLAYER_HAND,
    ON_NPC_BOARD,
    IN_NPC_DECK,
    IN_NPC_HAND,

    PLACE_MAX
};

struct CardParam
{
public:
    CardParam() : value( 0 ){};
    CardParam( const std::string& suit, u32 value )
    {
        this->suit  = suit;
        this->value = value;
    };

public:
    std::string suit;
    u32         value{ 0 };
};

USING_PTR( Card );
class Card : public Object
{
public:
    // create
    BP_OBJECT_TYPE( Card, Object );
    static CardPtr Create( CardParam param,
                           float3    model_pos = { 0.f, 0.f, 0.f },
                           float2    img_pos   = { 0.f, 0.f } );
    // auto run
    bool Init() override;
    void Update() override;
    void LateDraw() override;
    void GUI() override;
    void Exit() override;
    // callable function
    void RenderImg();
    // getter
    CardParam GetCardParam() const;
    // setter
    bool   Flip();
    float2 GetImgPos();
    float2 SetImgPos( float2 pos );
    // checker
    bool is_show   = false;
    bool is_touch  = false;
    bool is_select = false;

protected:
    // game paramenter
    CardParam param{};
    u32       place = NONE_PLACE;
    // image data
    float2 img_pos;
    Image  front_Img;
    Image  back_Img;
    // model data
    // materials data
    struct Material
    {
        std::shared_ptr<Texture> AO;
        std::shared_ptr<Texture> albedo;
        std::shared_ptr<Texture> normal;
        std::shared_ptr<Texture> roughness;
        std::shared_ptr<Texture> metalness;
    };
    std::vector<Material> materials;
};
using Cards = CardPtrVec;
