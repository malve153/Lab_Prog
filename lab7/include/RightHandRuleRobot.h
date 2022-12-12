#ifndef RIGHTHANDRULEROBOT_H
#define RIGHTHANDRULEROBOT_H
#include "Robot.h"

//a Robot that moves finding a wall and following it
class RightHandRuleRobot : public Robot{
public:
    RightHandRuleRobot(Tile mazePos) : Robot(mazePos), direction{'r'}, turn{0}{}
    void move(Maze& m) override;
    bool moveForward(Maze& m); //moves in the current direction
    void turnL(); //turns the current direction by 90° to the left and decrements turn by 1
    void turnR(); //turns the current direction by 90° to the right and increments turn by 1
    bool freeL(Maze& m); //check if the left tile is free
    bool freeR(Maze& m); //check if the right tile is free
private:
    char direction; //u = up, r = right, d = down, l = left
    int turn; //counts how many times it turns (left = -1, right = +1)
};

#include "RightHandRuleRobot.hpp"
#endif