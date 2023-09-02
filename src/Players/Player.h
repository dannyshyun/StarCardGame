#pragma once
#include <System/Scene.h>

USING_PTR( Player );
class Player : public Object
{
public:
    BP_OBJECT_TYPE( Player, Object );
    static PlayerPtr Create( float3 pos = {} );
    bool             Init() override;
    void             Update() override;
    void             Draw() override;
    void             Exit() override;

private:
    float3 pos{};
};
