#pragma once
#include <System/Scene.h>
#include <GameObjects/Deck.h>
#include <GameObjects/Hand.h>

USING_PTR( Player );
class Player : public Object
{
public:
    BP_OBJECT_TYPE( Player, Object );
    static PlayerPtr Create();
    bool             Init() override;
    void             Update() override;
    void             RenderImg();
    void             Exit() override;

    void SelectCard( CardPtr card );
    void CheckTouch( CardPtr card );

    void ClickOk();

private:
    float3                mdl_pos{};
    float2                img_pos{};
    std::shared_ptr<Deck> deck;
    std::shared_ptr<Hand> hand;
};
