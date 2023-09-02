#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionSphere.h>
#include "Frisbee.h"

BP_OBJECT_IMPL( Frisbee, "Frisbee" );
FrisbeePtr Frisbee::Create( float3 pos, float3 dir )
{
    auto obj = Scene::CreateObjectPtr<Frisbee>();
    obj->SetName( "Frisbee" );
    obj->pos = pos;
    obj->SetPositionAndDiraction( pos, dir );
    return obj;
}

bool Frisbee::Init()
{
    if( ! Super::Init() )
        return false;
    // model
    if( auto mdl = AddComponent<ComponentModel>() )
    {
        mdl->Load( "data/Model/Frisbee.mv1" );
        mdl->SetScaleAxisXYZ( 0.02f );
        // mdl->SetStatus( Component::StatusBit::NoDraw, true );
    }
    // collision
    if( auto coll = AddComponent<ComponentCollisionSphere>() )
    {
        coll->SetRadius( 0.3f );
        coll->SetHitCollisionGroup(
            (u32)ComponentCollision::CollisionGroup::ITEM |
            (u32)ComponentCollision::CollisionGroup::GROUND );
    }

    return true;
}

void Frisbee::Update()
{
    AddTranslate( this->dir * this->speed );
}

void Frisbee::Draw()
{
}

void Frisbee::Exit()
{
}

void Frisbee::SetPositionAndDiraction( const float3& pos, const float3& dir )
{
    auto mat = HelperLib::Math::CreateMatrixByFrontVector( dir );
    SetMatrix( mat );
    this->dir = normalize( dir );
    SetTranslate( pos );
}
