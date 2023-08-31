#pragma once
#include <System/Component/ComponentObjectController.h>

class PlayerController : public ComponentObjectController
{
public:
    BP_COMPONENT_TYPE( PlayerController, ComponentObjectController );
    void Init() override;
    void Update() override;

private:
    Object* player{};
    bool    throwing{};
    bool    prethrowing{};
    bool    dashing{};
};
