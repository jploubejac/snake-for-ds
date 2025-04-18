#include "SceneGame.hpp"
#include <nds.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "App.hpp"

SceneGame::SceneGame(App* pApp){
    this->pApp = pApp;
    this->isGameOver = false;
    this->waitForMove=0;
    this->generateFood();
}

void SceneGame::generateFood(){
    do{
        this->foodPosition.x = rand() % (SNAKE_POS_MAX_X - SNAKE_POS_MIN_X + 1) + SNAKE_POS_MIN_X;
        this->foodPosition.y = rand() % (SNAKE_POS_MAX_Y - SNAKE_POS_MIN_Y + 1) + SNAKE_POS_MIN_Y;
    }while(this->snake.SnakeIsOnCell(this->foodPosition));
}
void SceneGame::update(){

    if(keysDown() & KEY_SELECT) {
        this->snake.reset();
        this->isGameOver = false;
        this->generateFood();
        iprintf("=== Game Restarted ===\n");
    }
    if(keysDown() & KEY_R) {
        this->snake.SnakeGrowUp();
        this->generateFood();
    }
    if(keysDown() & KEY_START) {
        this->pApp->changeScene(App::AppScene::APP_SCENE_MAIN_MENU);
    }

    if(this->isGameOver)return;
    
    if(keysDown() & KEY_RIGHT) {
        this->snake.changeDirection(Snake::SnakeDirection::SNAKE_RIGHT);
    }
    if(keysDown() & KEY_LEFT) {
        this->snake.changeDirection(Snake::SnakeDirection::SNAKE_LEFT);
    }
    if(keysDown() & KEY_UP) {
        this->snake.changeDirection(Snake::SnakeDirection::SNAKE_UP);
    }
    if(keysDown() & KEY_DOWN) {
        this->snake.changeDirection(Snake::SnakeDirection::SNAKE_DOWN);
    }
    this->waitForMove++;
    if(this->waitForMove > (SNAKE_MAX_LENGTH-this->snake.getSize())/16){
        this->snake.move();
        if(this->snake.SnakeIsBiteHimself()){
            this->isGameOver=true;
            iprintf("=== Game Over ===\n");
            iprintf("Vous avez mangé votre queue !\n");
            iprintf("Votre score est de %d\n", this->snake.getSize());
            iprintf("Appuyer sur Select pour recommencer\n");
            return;
        }
        if(this->snake.SnakeIsFoodDetected(this->foodPosition)){
            this->snake.SnakeGrowUp();
            this->generateFood();
        }
        this->waitForMove=0;
    }
}

void SceneGame::draw(){
    const Snake::SnakePosition* positions= this->snake.getPositions();
    int size = this->snake.getSize();
    for (int y = 0; y <= SNAKE_POS_MAX_Y; y++) {
        for (int x = 0; x <= SNAKE_POS_MAX_X; x++) {
            drawTile(x, y, SCENE_GAME_TILE_EMPTY);
        }
    }
    for(int i=0;i<size;i++){
        if(i==0){
            switch(this->snake.getHeadDirection()){
                case Snake::SnakeDirection::SNAKE_UP:
                    drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_HEAD_UP);
                    break;
                case Snake::SnakeDirection::SNAKE_DOWN:
                    drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_HEAD_DOWN);
                    break;
                case Snake::SnakeDirection::SNAKE_LEFT:
                    drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_HEAD_LEFT);
                    break;
                case Snake::SnakeDirection::SNAKE_RIGHT:
                    drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_HEAD_RIGHT);
                    break;
            }
        }
        else if(i==size-1){
            switch(this->snake.getTailDirection()){
                case Snake::SnakeDirection::SNAKE_UP:
                    drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_TAIL_UP);
                    break;
                case Snake::SnakeDirection::SNAKE_DOWN:
                    drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_TAIL_DOWN);
                    break;
                case Snake::SnakeDirection::SNAKE_LEFT:
                    drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_TAIL_LEFT);
                    break;
                case Snake::SnakeDirection::SNAKE_RIGHT:
                    drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_TAIL_RIGHT);
                    break;
            }
        }
        else{
            drawTile(positions[i].x, positions[i].y, SCENE_GAME_TILE_BODY);
        }
    }
    drawTile(this->foodPosition.x, this->foodPosition.y, SCENE_GAME_TILE_FOOD);
}

void SceneGame::drawTile(int x, int y, int tile){
    int realX = x * 2;
    int realY = y * 2;
    int realTile = tile * 2;
    BG_MAP_RAM(31)[(realY * 32) + realX] = realTile;
    BG_MAP_RAM(31)[(realY * 32) + realX+1] = realTile+1;
    BG_MAP_RAM(31)[((realY+1) * 32) + realX] = realTile+22;
    BG_MAP_RAM(31)[((realY+1) * 32) + realX+1] = realTile+23;
}