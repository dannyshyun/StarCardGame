#pragma once
#include <System/Scene.h>

USING_PTR( Table );
class Table : public Object
{
public:
    BP_OBJECT_TYPE( Table, Object );
    static TablePtr Create( float3 pos = { 0.f, 0.f, 0.f } );
    virtual bool    Init() override;
    virtual void    Update() override;
    virtual void    Render();
    virtual void    GUI() override;
    virtual void    Exit() override;

protected:
    int    image = -1;
    u32    value = 0;
    u32    part  = 0;
    float2 image_size{ 0.f, 0.f };

    struct Material
    {
        std::shared_ptr<Texture> AO;
        std::shared_ptr<Texture> albedo;
        std::shared_ptr<Texture> normal;
        std::shared_ptr<Texture> roughness;
        std::shared_ptr<Texture> metalness;
    };

    std::vector<Material> materials;
};