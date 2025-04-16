#include <nds.h>
#include <stdio.h>
#include "SceneMenu.hpp"

SceneMenu::SceneMenu(App* app){
    this->app = app;
    this->areChanged = false;
    iprintf("=== Menu ===\n");
    iprintf("Bienvenue dans le snake ds\n");
    iprintf("Appuyer sur Start pour commencer le jeu\n");
}

void SceneMenu::draw() {
    if (this->areChanged) {
        iprintf("Bouton Start appuyé\n");
        this->areChanged = false;
    }
}

void SceneMenu::update() {
    if(keysDown() & KEY_START) {
        this->areChanged = true;
        //this->app->changeScene(App::AppScene::GAME);
    }
}
