#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionSphere.h>
#include "Frisbee.h"

BP_OBJECT_IMPL( Frisbee, "Frisbee" );
FrisbeePtr Frisbee::Create( float3 pos, float3 dir )
{
    auto obj = Scene::CreateObjectPtr<Frisbee>();
    obj->SetName( "Frisbee" );
    obj->pos = pos;
    obj->dir = dir;
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

    return true;
}

void Frisbee::Update()
{
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
    SetTranslate( pos );
}
