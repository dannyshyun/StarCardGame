#include <System/Component/ComponentModel.h>
#include "Frisbee.h"

BP_OBJECT_IMPL( Frisbee, "Frisbee" );
FrisbeePtr Frisbee::Create( float3 pos )
{
    auto obj = Scene::CreateObjectPtr<Frisbee>();
    obj->SetName( "Frisbee" );
    obj->pos = pos;
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
