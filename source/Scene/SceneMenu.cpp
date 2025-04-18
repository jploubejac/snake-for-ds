#include <nds.h>
#include <stdio.h>
#include "SceneMenu.hpp"
#include "App.hpp"

SceneMenu::SceneMenu(App* pApp){
    this->pApp = pApp;
    this->areChanged = false;
    iprintf("=== Menu ===\n");
    iprintf("Bienvenue dans le snake ds\n");
    iprintf("Appuyer sur Start pour commencer le jeu\n");
}

void SceneMenu::draw() {

}

void SceneMenu::update() {
    if(keysDown() & KEY_START) {
        this->areChanged = true;
        this->pApp->changeScene(App::AppScene::APP_SCENE_GAME);
    }
}
