#include <System/Scene.h>

USING_PTR( CameraBase );

class CameraBase : public Object
{
public:
    BP_OBJECT_TYPE( CameraBase, Object );
    static CameraBasePtr Create( float3 pos, float3 target );

    bool Init() override;
#ifdef USE_MOUSE_CAMERA
    void Update() override;
#endif
protected:
    float3 pos{};
    float3 target{};
    float3 rot{ -20, 0, 0 };
};
