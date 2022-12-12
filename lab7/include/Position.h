#ifndef POSITION_H
#define POSITION_H

// class to handle the position of the robot or a tile
class Position{
public:
    Position(int x=0, int y=0);
    bool operator==(const Position& p);
    bool operator!=(const Position& p);
    Position getPosition(){ return Position(x,y); }
    void setX(int posX) { x = posX;}
    void setY(int posY) { y = posY;}
    int getX() { return x; }
    int getY() { return y; }
private:
    int x;
    int y;    
};

#include "Position.hpp"
#endif