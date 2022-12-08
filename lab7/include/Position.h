#ifndef POSITION_H
#define POSITION_H

class Position{
public:
    Position(int x=0, int y=0);
    void setPosition(int x, int y);
    void setX(int posX) { x = posX;}
    void setY(int posY) { y = posY;}
    Position getPosition(){ return Position(x,y); }
    int getX() { return x; }
    int getY() { return y; }
private:
    int x;
    int y;    
};

#include "Position.hpp"
#endif