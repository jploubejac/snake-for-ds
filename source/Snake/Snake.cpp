#include "Snake.hpp"

Snake::Snake(){
    this->size=1;
    this->directions[0]=SNAKE_UP;
    this->positions[0]=SnakePosition((SNAKE_POS_MIN_X+SNAKE_POS_MAX_X)/2,(SNAKE_POS_MIN_Y+SNAKE_POS_MAX_Y)/2);
    while(this->size<SNAKE_INIT_LENGTH)this->SnakeGrowUp();
}

void Snake::move(){
    for (int i = this->size - 1; i > 0; i--) {
        this->positions[i] = this->positions[i - 1];
        this->directions[i] = this->directions[i - 1];
    }

    switch (this->directions[0]) {
        case SNAKE_UP:
            if(this->positions[0].y==SNAKE_POS_MIN_Y)this->positions[0].y=SNAKE_POS_MAX_Y;
            else this->positions[0].y--;
            break;
        case SNAKE_DOWN:
            if(this->positions[0].y==SNAKE_POS_MAX_Y)this->positions[0].y=SNAKE_POS_MIN_Y;
            else this->positions[0].y++;
            break;
        case SNAKE_LEFT:
            if(this->positions[0].x==SNAKE_POS_MIN_X)this->positions[0].x=SNAKE_POS_MAX_X;
            else this->positions[0].x--;
            break;
        case SNAKE_RIGHT:
            if(this->positions[0].x==SNAKE_POS_MAX_X)this->positions[0].x=SNAKE_POS_MIN_X;
            else this->positions[0].x++;
            break;
    }
}

void Snake::changeDirection(SnakeDirection newDirection){
    if (this->size == 0) return; 

    SnakeDirection oppositeDirection;
    switch (this->directions[0]) {
        case SNAKE_UP:
            oppositeDirection = SNAKE_DOWN;
            break;
        case SNAKE_DOWN:
            oppositeDirection = SNAKE_UP;
            break;
        case SNAKE_LEFT:
            oppositeDirection = SNAKE_RIGHT;
            break;
        case SNAKE_RIGHT:
            oppositeDirection = SNAKE_LEFT;
            break;
    }

    if (newDirection != oppositeDirection) {
        this->directions[0] = newDirection;
    }
}

int Snake::getSize() const{
    return this->size;
}

int Snake::SnakeIsFoodDetected(SnakePosition foodPosition){
    if (this->positions[0].x == foodPosition.x && this->positions[0].y == foodPosition.y) {
        return 1; 
    }
    return 0; 
}

const Snake::SnakePosition *Snake::getPositions() const{
    return this->positions;
}

void Snake::SnakeGrowUp(){
    
    if (this->size >= SNAKE_MAX_LENGTH)return; 

    SnakeDirection lastDir = this->directions[this->size - 1];
    SnakePosition lastPos = this->positions[this->size - 1];
    SnakePosition newPos;

    switch (lastDir) {
        case SNAKE_UP:
            newPos = SnakePosition(lastPos.x, lastPos.y + 1);
            break;
        case SNAKE_DOWN:
            newPos = SnakePosition(lastPos.x, lastPos.y - 1);
            break;
        case SNAKE_LEFT:
            newPos = SnakePosition(lastPos.x + 1, lastPos.y);
            break;
        case SNAKE_RIGHT:
            newPos = SnakePosition(lastPos.x - 1, lastPos.y);
            break;
    }

    this->positions[this->size] = newPos;
    this->directions[this->size] = lastDir;
    this->size++;
}

int Snake::SnakeIsBiteHimself(){
    SnakePosition head = this->positions[0];
    for (int i = 1; i < this->size; i++) {
        if (this->positions[i].x == head.x && this->positions[i].y == head.y) {
            return 1; 
        }
    }
    return 0; 
}

int Snake::SnakeIsOnCell(SnakePosition cell){
    for (int i = 0; i < this->size; i++) {
        if (this->positions[i].x == cell.x && this->positions[i].y == cell.y) {
            return 1; 
        }
    }
    return 0; 
}