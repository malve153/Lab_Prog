#include <iostream>
#include "Maze.h"

int main(){
    Maze m(9,9);
    m.fillMaze("maze.txt");
    m.printMaze();
    m.movePos(1);
    m.movePos(0,1);
    m.movePos(-1,0);
    m.printMaze();
    return 0;
}