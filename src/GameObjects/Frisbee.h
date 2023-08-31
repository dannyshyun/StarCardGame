#pragma once
#include <System/Scene.h>

USING_PTR( Frisbee );
class Frisbee : public Object
{
public:
    BP_OBJECT_TYPE( Frisbee, Object );
    static FrisbeePtr Create( float3 pos = {}, float3 dir = {} );
    bool              Init() override;
    void              Update() override;
    void              Draw() override;
    void              Exit() override;

    void SetPositionAndDiraction( const float3& pos, const float3& dir );

private:
    float3 pos{};
    float3 dir{};
    f32    speed{ 100.f };
    f32    radius{ 1.f };
};