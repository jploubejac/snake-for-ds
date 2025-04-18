#ifndef APP_HPP
#define APP_HPP

#include "Scene.hpp"
#include "SceneMenu.hpp"
#include "SceneGame.hpp"

class App{
    public:
        enum class AppScene{
            APP_SCENE_MAIN_MENU,
            APP_SCENE_GAME,
            APP_SCENE_GAME_OVER
        };
    private:
        SceneMenu *pSceneMenu;
        SceneGame *pSceneGame;
        Scene *currentScene;
        
    public:
        App();
        void init();
        void run();
        void changeScene(AppScene newScene);

};

#endif