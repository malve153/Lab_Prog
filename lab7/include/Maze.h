#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Tile.h"

//class that inserts the characters contained in the file into the matrix 
//and manages the operations concerning the maze
class Maze{
public:
    Maze(int nRow, int nCol);
    void fillMaze(std::string file_name);
    bool movePos(Position p); //move actual_pos to the position p
    bool checkWallUp(); //check if the upper tile contains a wall
    bool checkWallRight(); //check if the right tile contains a wall
    bool checkWallLeft(); //check if the left tile contains a wall
    bool checkWallDown(); //check if the down tile contains a wall
    void printMaze();
    Tile getPosAt(Position p); //returns the tile in position p
    Tile getActual_pos() { return actual_pos; }

private:
    std::vector<std::vector<Tile> > matrix;
    Tile actual_pos;
};

#include "Maze.hpp"
#endif