#pragma once
#include <System/Scene.h>

USING_PTR( Dice );
class Dice : public Object
{
public:
    BP_OBJECT_TYPE( Dice, Object );
    static DicePtr Create( std::string color, float3 pos = { 0.f, 1.5f, 0.f } );
    virtual bool   Init() override;
    virtual void   Update() override;
    virtual void   Render();
    virtual void   GUI() override;
    virtual void   Exit() override;

protected:

    std::string color;

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