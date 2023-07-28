#pragma once
class Image final
{
public:
    Image();
    Image( float2 pos, int handle );
    ~Image();

    void Update();

    void Render();

    void Release();

private:
    float2 pos;
    int handle;
};
