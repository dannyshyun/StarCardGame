#pragma once
#include <System/Scene.h>
#include <utility>
#include "UI/Image.h"

struct CardParam
{
public:
    CardParam() : value( 0 ){};
    CardParam( const std::string& suit, u32 value )
    {
        this->suit  = std::move( suit );
        this->value = value;
    };

public:
    std::string suit;
    u32         value{ 0 };
};

USING_PTR( CardTest );
class CardTest : public Object
{
public:
    BP_OBJECT_TYPE( CardTest, Object );
    static CardTestPtr              Create( CardParam param,
                                            float3    model_pos = { 0.f, 0.f, 0.f },
                                            float2    img_pos = { 0.f, 0.f } );
    virtual bool                    Init() override;
    virtual void                    Update() override;
    virtual void                    Render( bool is_show );
    void                            LateDraw() override;
    virtual void                    GUI() override;
    virtual void                    Exit() override;
    [[nodiscard]] virtual CardParam GetCardParam() const;

    bool is_player = true;
    bool is_select = false;
    bool is_touch  = false;

protected:
    // 2D image data
    Image frontImg;
    Image backImg;
    // materials
    struct Material
    {
        std::shared_ptr<Texture> AO;
        std::shared_ptr<Texture> albedo;
        std::shared_ptr<Texture> normal;
        std::shared_ptr<Texture> roughness;
        std::shared_ptr<Texture> metalness;
    };
    std::vector<Material> materials;

    // card suit and value
    CardParam param{};
};
