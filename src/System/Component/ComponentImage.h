#pragma once

#include <System/Component/Component.h>
#include <System/Object.h>

#include <ImGuizmo/ImGuizmo.h>
#include <DxLib.h>

USING_PTR( ComponentImage );
class ComponentImage : public Component
{
public:
    BP_COMPONENT_TYPE( ComponentImage, Component );
    ComponentImage() {}
}