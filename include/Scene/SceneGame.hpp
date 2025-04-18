#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "Scene.hpp"
#include "Snake.hpp"
class App; // Forward declaration

class SceneGame : public Scene{
    private:
        App *pApp;
        Snake snake;
        Snake::SnakePosition foodPosition;
        bool isGameOver;
        int waitForMove;
        void generateFood();
    public:
        SceneGame(App *pApp);
        void draw() override;
        void update() override;
        void drawTile(int x, int y, int tile);
};

#endif