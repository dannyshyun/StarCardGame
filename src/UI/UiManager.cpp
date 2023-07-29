#include "UiManager.h"
BP_OBJECT_IMPL( UiManager, "UiManager" );
UiManagerPtr UiManager::Create( CardTestPtr        cardTest,
                                ComponentCameraPtr currentCam )
{
    auto obj = Scene::CreateObjectPtr<UiManager>();
    obj->cardTest = cardTest;
    obj->currentCamera = currentCam;
    return obj;
}
UiManager::UiManager()
{
}

UiManager::~UiManager()
{
}

bool UiManager::Init()
{
    return __super::Init();
}

void UiManager::Update()
{
}

void UiManager::LateDraw()
{
    if (currentCamera->GetOwner()->GetName() == "TopCamera") {
        cardTest->RenderImg();
    }
}


