#pragma once

class UI
{
public:
    UI();
    void Init();
    void Update();
    void Render();
    void Release();

private:
    void DrawMove();
};
