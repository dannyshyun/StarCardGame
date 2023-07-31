#pragma once
#include "GameObjects/Card.h"

class Deck
{
public:
    Deck();
    Deck( bool is_player );
    ~Deck();
    void Init();
    void Update();
    void RenderImg();
    void Release();

    // revoke cards which are folded
    void Revoke( Cards cards );
    // load turn
    bool Load();
    // shuffle turn
    bool Shuffle();

    // deal cards from deck
    Cards Deal( u32 num );
    // get card num from deck
    u32 GetNum() const;

private:

    // model data
    float3 mdl_pos{};
    // image data
    float2 img_pos{};
    Image  img{};
    // card container
    Cards deck{};
    // the number of card to render
    u32 num = 0;
};
