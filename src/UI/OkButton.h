#pragma once
#include <stdint.h>

class OkBtn : public Base
{
public:
    OkBtn( int image );
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
};
