#pragma once
#include <stdint.h>
#include "GameObjects/Card.h"

const u32 HAND_MAX( 7 );

class Hand
{
public:
    Hand();
    Hand( bool is_player );
    ~Hand();
    void Init();
    void Update();
    void RenderImg();
    void Release();

    Cards Fold( Cards cards );
    void  Draw( Cards cards );
    u32   GetHandNum() const;
    Cards GetHandCards() const;

private:
    float3 mdl_pos{};
    float2 img_pos{};
    Cards  hand;
};
