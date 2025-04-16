#include <nds.h>
#include "App.hpp"


App::App(){
    consoleDemoInit();
    this->pSceneMenu = new SceneMenu(this);
    this->changeScene(App::AppScene::APP_SCENE_MAIN_MENU);
}

void App::run(){
    while(1){
        scanKeys();
        this->currentScene->update();
        this->currentScene->draw();
        swiWaitForVBlank();
    }
}

void App::changeScene(App::AppScene newScene){
    switch (newScene) {
        case App::AppScene::APP_SCENE_MAIN_MENU:
            this->currentScene = this->pSceneMenu;
            break;
        case App::AppScene::APP_SCENE_GAME:
            //this->currentScene = &this->sceneGame;
            break;
        case App::AppScene::APP_SCENE_GAME_OVER:
            //this->currentScene = &this->sceneGameOver;
            break;
    }
}