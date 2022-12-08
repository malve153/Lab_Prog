#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Tile.h"

class Maze{
public:
    Maze(int nRow, int nCol);
    void fillMaze(std::string file_name);
    void movePos(int x=0,int y=0);
    void printMaze();

private:
    std::vector<std::vector<Tile> > matrix;
    Tile actual_pos;
};

#include "Maze.hpp"
#endif