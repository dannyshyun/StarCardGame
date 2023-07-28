#pragma once
class ItemCard : public CardBase
{
public:
    ItemCard( int image, u32 value, u32 part );
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render( bool is_show ) override;
    virtual void Release() override;

protected:
};
