#include "Camera.h"
#include <System/Component/ComponentCollisionSphere.h>
#include <System/Component/ComponentSpringArm.h>

BP_OBJECT_IMPL( Camera, "Camera" );

CameraPtr Camera::Create( ObjectPtr target )
{
    auto obj    = Scene::CreateObjectDelayInitialize<Camera>();
    obj->target = target;
    return obj;
}

bool Camera::Init()
{
    if( ! __super::Init() )
        return false;

    auto cam = AddComponent<ComponentCamera>();
    cam->SetPositionAndTarget( float3( 0, 0, -1 ), float3( 0 ) );
    cam->SetPerspective( 60.0f * DegToRad );

    auto coll = AddComponent<ComponentCollisionSphere>();
    coll->SetRadius( 2.f );
    coll->SetMass( 0.f );

    auto arm = AddComponent<ComponentSpringArm>();
    arm->SetSpringArmObject( this->target.lock() );
    arm->SetSpringArmVector( float3( 0, 15, 180 ) );
    arm->SetSpringArmLength( 200 );
    arm->SetSpringArmOffset( float3( 0, 1.3, 22.6 ) );

    return true;
}

#ifdef USE_MOUSE_CAMERA
void Camera::Update()
{
    auto spring_arm = GetComponent<ComponentSpringArm>();

    // SprintArm�̉�]�Ƀ}�E�X�̈ړ��ʂ𑫂�����
    rot += { GetMouseMoveY(), GetMouseMoveX(), 0 };

    // �������񂾉�]�𗘗p����
    spring_arm->SetSpringArmRotate( rot );
}
#endif