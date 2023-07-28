#pragma once

class UI : public Base
{
public:
    UI( int image );
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;

private:
    void DrawMove();
};
