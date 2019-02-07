#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>

class Snake {

public:
    Snake ();
    ~Snake ();
    void addToTail ();
    int getLenght();
    int getArrEll(int, int);
    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();
    int getKeyBlock();
    void randomizeAppleCoords();
    int getXApple();
    int getYApple();
    bool checkCollisions();
        
        
private:
    int snake_array [2][100];
    int lenght;
    int keyBlock;
    int xApple = 3, yApple = 3;
    int xTail, yTail;
    
};

#endif /* SNAKE_H */

