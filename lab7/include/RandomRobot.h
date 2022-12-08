#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H
#include "Robot.h"

class RandomRobot : public Robot{
    RandomRobot(Tile mazePos) : Robot(mazePos){}
    //void move(Maze& m) override;
};


#endif