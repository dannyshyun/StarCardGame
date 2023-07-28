#pragma once
#include <GameSystem/Vector2.h>
#include <GameSystem/Vector3.h>

//---------------------------------------------------------------------------------
//	基本クラス
//---------------------------------------------------------------------------------
class Base
{
public:
    Base( int image );
    virtual void Init();
    virtual void Update();
    virtual void Render();
    virtual void Release();

    Vector2 pos;
    Vector2 rot;
    Vector2 size;
    float   radius;

protected:
    int model;
    int image;
};
