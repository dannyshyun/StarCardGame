#pragma once
#include <System/Scene.h>
#include <GameObjects/Deck.h>
#include <GameObjects/Hand.h>

USING_PTR( Npc );
class Npc : public Object
{
public:
    BP_OBJECT_TYPE( Npc, Object );
    static NpcPtr Create();
    bool          Init() override;
    void          Update() override;
    void          RenderImg();
    void          Exit() override;
    void          SelectCard( CardPtr card );

private:
    float3                mdl_pos{};
    float2                img_pos{};
    std::shared_ptr<Deck> deck;
    std::shared_ptr<Hand> hand;
};
