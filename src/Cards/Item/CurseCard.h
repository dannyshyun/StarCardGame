#pragma once
class CurseCard : public ItemCard
{
public:
    CurseCard( int image, u32 value, u32 part );
    void Init() override;
    void Update() override;
    void Render( bool is_show ) override;
    void Release() override;

private:
};