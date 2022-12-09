#ifndef RIGHTHANDRULEROBOT_H
#define RIGHTHANDRULEROBOT_H
#include "Robot.h"

class RightHandRuleRobot : public Robot{
public:
    RightHandRuleRobot(Tile mazePos) : Robot(mazePos), direction{'r'}, turn{0}{}
    void move(Maze& m) override;
    bool moveForward(Maze& m);
    void turnL();
    void turnR();
    bool freeL(Maze& m);
    bool freeR(Maze& m);
private:
    char direction;
    int turn;
};

#include "RightHandRuleRobot.hpp"
#endif