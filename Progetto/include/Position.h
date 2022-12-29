#ifndef POSITION_H
#define POSITION_H
#include <iostream>

class Position
{
public:
    Position(char x = 'A',int y = 0) : row{x}, col{y} {}
    bool operator==(const Position& p);
    bool operator!=(const Position& p);
    Position getPosition(){ return Position(row,col); }
    void setRow(char pos) { row = pos;}
    void setCol(int pos) { col = pos;}
    char getRow() { return row; }
    int getCol() { return col; }
    friend std::ostream& operator<<(std::ostream& os, Position& p);
protected:
    char row;
    int col;
};

#include "Position.hpp"
#endif