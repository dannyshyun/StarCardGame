#pragma once
class ChanceCard : public ItemCard
{
public:
    ChanceCard( int image, u32 value, u32 part );
    void Init() override;
    void Update() override;
    void Render( bool is_show ) override;
    void Release() override;

private:
};