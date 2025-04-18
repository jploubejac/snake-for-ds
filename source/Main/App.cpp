#include <nds.h>
#include "App.hpp"
#include "../data/snake_tiles_V2.h"


App::App(){
}

void App::init(){
    consoleDemoInit();
    videoSetMode(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_BG);
    int bgId=bgInit(0, BgType_Text8bpp, BgSize_T_256x256, 31, 0);
    dmaCopy(snake_tiles_V2Pal, BG_PALETTE, snake_tiles_V2PalLen);
    dmaCopy(snake_tiles_V2Tiles, bgGetGfxPtr(bgId), snake_tiles_V2TilesLen);
    this->pSceneMenu = new SceneMenu(this);
    this->pSceneGame = new SceneGame(this);
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
            this->currentScene = this->pSceneGame;
            break;
        case App::AppScene::APP_SCENE_GAME_OVER:
            //this->currentScene = &this->sceneGameOver;
            break;
    }
}