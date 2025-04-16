#ifndef APP_HPP
#define APP_HPP

#include "Scene.hpp"
#include "SceneMenu.hpp"

class App{
    public:
        enum class AppScene{
            APP_SCENE_MAIN_MENU,
            APP_SCENE_GAME,
            APP_SCENE_GAME_OVER
        };
    private:
        SceneMenu *pSceneMenu;
        Scene *currentScene;
        
    public:
        App();
        void run();
        void changeScene(AppScene newScene);

};

#endif