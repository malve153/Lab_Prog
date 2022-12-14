#include <iostream>
#include "Maze.h"
#include "RandomRobot.h"
#include "RightHandRuleRobot.h"

#ifdef _WIN32
#  include <Windows.h>
#  define sleep_function         Sleep
#  define time_multiplier        1
#else
#  include <unistd.h>
#  define sleep_function         usleep
#  define time_multiplier        1000
#endif

int main(){
    constexpr int NROW = 10;
    constexpr int NCOL = 20;
    Maze m(NROW,NCOL);
    m.fillMaze("maze2.txt");
    //---------ROBOT--------------------------
    std::cout<<"Right Hand Robot --------------------------------------------\n";
    RightHandRuleRobot r(m.getActual_pos());
    std::cout << "posizione del robot: [" << r.getPos().getX() << "]["<< r.getPos().getY()  <<"]\n";
    m.printMaze();
    r.move(m);
    std::cout << "posizione del robot: [" << r.getPos().getX() << "]["<< r.getPos().getY()  <<"]\n"; 
    std::cout<<"STARTING RANDOM ROBOT IN 3..\n";
    sleep_function(time_multiplier * 1000);
    std::cout<<"2..\n";
    sleep_function(time_multiplier * 1000);
    std::cout<<"1..\n";
    sleep_function(time_multiplier * 1000);
    std::cout << "Random Robot ----------------------------------------------\n";
    Maze m2(NROW,NCOL);
    m2.fillMaze("maze2.txt");
    RandomRobot r1(m2.getActual_pos());
    std::cout << "posizione del robot: [" << r1.getPos().getX() << "]["<< r1.getPos().getY()  <<"]\n";
    r1.move(m2);
    std::cout << "posizione del robot: [" << r1.getPos().getX() << "]["<< r1.getPos().getY()  <<"]\n";
    
    //--------------------------------------------------
    return 0;
}