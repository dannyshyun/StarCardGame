#pragma once
#include <System/Scene.h>
#include <Players/Player.h>
#include <Players/Npc.h>
#include <UI/UI.h>
namespace MainScene
{
    namespace Scene3D
    {
        class TestScene : public Scene::Base
        {
        public:
            BP_CLASS_TYPE( TestScene, Scene::Base );

            bool Init() override;
            void Update() override;
            void Draw() override;
            void LateDraw() override;
            void Exit() override;

            void GUI() override;

        private:
            int counter = 0;
        };
    }
    namespace Scene2D
    {

    };
}
