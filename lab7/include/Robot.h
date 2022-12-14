#ifndef ROBOT_H
#define ROBOT_H
#include "Maze.h"

class Robot{
public:
    Robot(Tile mazePos);
    virtual void move(Maze& m) = 0;
    Position getPos(){ return pos; }
protected:
    Position pos;
};

#include "Robot.hpp"
#endif