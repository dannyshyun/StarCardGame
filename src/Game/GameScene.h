#pragma once
#include <System/Scene.h>
#include <Characters/Player.h>
#include <Characters/Npc.h>
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
            void Exit() override;

            void GUI() override;

        private:
            int counter = 0;

            std::unique_ptr<Player> player = std::make_unique<Player>( 0 );
            std::unique_ptr<Npc>    npc    = std::make_unique<Npc>( 0 );
            std::unique_ptr<UI>     ui     = std::make_unique<UI>( 0 );
        };
    }
    namespace Scene2D
    {

    };
}
