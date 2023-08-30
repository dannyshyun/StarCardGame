#include <System/Scene.h>

USING_PTR( Camera );

class Camera : public Object
{
public:
    BP_OBJECT_TYPE( Camera, Object );
    static CameraPtr Create( ObjectPtr target );

    bool Init() override;

private:
    ObjectWeakPtr target{};
    float3        rot{ -20, 0, 0 };
};
