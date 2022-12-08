#ifndef ROBOT_H
#define ROBOT_H
#include "Maze.h"

class Robot{
public:
    Robot(Tile mazePos);
    virtual void move(Position p);
    Position getPos(){ return pos; }
private:
    Position pos;
};

#include "Robot.hpp"
#endif