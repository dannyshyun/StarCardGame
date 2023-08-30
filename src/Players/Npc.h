#pragma once
#include <System/Scene.h>

USING_PTR( Npc );
class Npc : public Object
{
public:
    BP_OBJECT_TYPE( Npc, Object );
    static NpcPtr Create( float3 pos = {} );
    bool          Init() override;
    void          Update() override;
    void          Draw() override;
    void          Exit() override;

private:
    float3 pos{};
};
