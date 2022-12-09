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
    bool movePos(Position p);
    bool checkWallUp();
    bool checkWallRight();
    bool checkWallLeft();
    bool checkWallDown();
    void printMaze();
    Tile getPosAt(Position p);
    Tile getActual_pos() { return actual_pos; }

private:
    std::vector<std::vector<Tile> > matrix;
    Tile actual_pos;
};

#include "Maze.hpp"
#endif