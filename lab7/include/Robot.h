#ifndef ROBOT_H
#define ROBOT_H
#include "Maze.h"

class Robot{
public:
    Robot(Tile mazePos): pos{mazePos.getPosition()}{};
    virtual void move(Maze& m) = 0;
    Position getPos(){ return pos; }
protected:
    Position pos;
};
#endif