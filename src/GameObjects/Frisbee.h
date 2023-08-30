#pragma once
#include <System/Scene.h>

USING_PTR( Frisbee );
class Frisbee : public Object
{
public:
    BP_OBJECT_TYPE( Frisbee, Object );
    static FrisbeePtr Create( float3 pos = {} );
    bool              Init() override;
    void              Update() override;
    void              Draw() override;
    void              Exit() override;

private:
    float3 pos{};
};