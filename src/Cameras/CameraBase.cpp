#include "CameraBase.h"
#include <System/Component/ComponentCollisionSphere.h>
#include <System/Component/ComponentSpringArm.h>

BP_OBJECT_IMPL( CameraBase, "Camera" );

CameraBasePtr CameraBase::Create( float3 pos, float3 target )
{
    auto obj    = Scene::CreateObjectDelayInitialize<CameraBase>();
    obj->pos    = pos;
    obj->target = target;
    return obj;
}

bool CameraBase::Init()
{
    if( ! __super::Init() )
        return false;

    auto cam = AddComponent<ComponentCamera>();
    cam->SetPositionAndTarget( pos, target );
    cam->SetPerspective( 60.0f * DegToRad );

    return true;
}

#ifdef USE_MOUSE_CAMERA
void CameraBase::Update()
{
    auto spring_arm = GetComponent<ComponentSpringArm>();

    // SprintArm�̉�]�Ƀ}�E�X�̈ړ��ʂ𑫂�����
    rot += { GetMouseMoveY(), GetMouseMoveX(), 0 };

    // �������񂾉�]�𗘗p����
    spring_arm->SetSpringArmRotate( rot );
}
#endif
