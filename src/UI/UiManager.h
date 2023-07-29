#pragma once
#include <System/Scene.h>
#include "Cards/CardTest.h"

USING_PTR( UiManager );
class UiManager :public Object
{
public:
    BP_OBJECT_TYPE( UiManager, Object );
    static UiManagerPtr Create(CardTestPtr cardTest,ComponentCameraPtr currentCam);
    UiManager();
    ~UiManager();

    bool Init() override;

    void Update() override;

    void LateDraw() override;


private:
    CardTestPtr cardTest;
    ComponentCameraPtr currentCamera;
};
