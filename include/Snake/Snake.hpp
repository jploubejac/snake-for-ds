#ifndef SNAKE_HPP
#define SNAKE_HPP 

#include "parameters.h"
class Snake {
public: 
    enum SnakeDirection{
            SNAKE_UP,
            SNAKE_DOWN,
            SNAKE_LEFT,
            SNAKE_RIGHT
    };
    class SnakePosition{
        int x;
        int y;
        SnakePosition(int x, int y){
            this->x=x;
            this->y=y;
        }
    };
private:
    int size;
    SnakeDirection directions[SNAKE_MAX_LENGTH];
    SnakePosition positions[SNAKE_MAX_LENGTH];
public:
    Snake();
    void move();
    void changeDirection(SnakeDirection newDirection);
    int getSize() const;
    void SnakeGrowUp();
    int SnakeIsFoodDetected(SnakePosition foodPosition);
    const SnakePosition *getPositions() const;
    int SnakeIsBiteHimself();
    int SnakeIsOnCell(SnakePosition cell);
}

#endif