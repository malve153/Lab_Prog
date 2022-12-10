#include <iostream>
#include "Maze.h"
#include "RandomRobot.h"
#include "RightHandRuleRobot.h"

int main(){
    constexpr int NROW = 9;
    constexpr int NCOL = 9;
    Maze m(NROW,NCOL);
    m.fillMaze("maze.txt");
    //---------ROBOT--------------------------
    RightHandRuleRobot r(m.getActual_pos());
    std::cout << "posizione del robot: [" << r.getPos().getX() << "]["<< r.getPos().getY()  <<"]\n";
    m.printMaze();
    r.move(m);
    m.printMaze();
    std::cout << "posizione del robot: [" << r.getPos().getX() << "]["<< r.getPos().getY()  <<"]\n"; 
    /*RandomRobot r(m.getActual_pos());
    std::cout << "posizione del robot: [" << r.getPos().getX() << "]["<< r.getPos().getY()  <<"]\n";
    m.printMaze();
    r.move(m);
    m.printMaze();
    std::cout << "posizione del robot: [" << r.getPos().getX() << "]["<< r.getPos().getY()  <<"]\n";
    */
    //--------------------------------------------------
    return 0;
}