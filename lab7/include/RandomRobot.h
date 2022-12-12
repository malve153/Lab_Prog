#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H
#include "Robot.h"

//a Robot that moves chosing a random direction
class RandomRobot : public Robot{
public:
    RandomRobot(Tile mazePos) : Robot(mazePos){ srand(time(NULL)); }
    void move(Maze& m) override;
};

#include "RandomRobot.hpp"
#endif