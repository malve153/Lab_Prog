#ifndef TILE_H
#define TILE_H
#include "Position.h"

class Tile : public Position
{
public:
    Tile(char v = ' ', char posX = 'A', int posY = 0);
    char getValue(){ return value;}
    void setValue(char c);
    friend std::ostream& operator<<(std::ostream& os, Tile& t);
private:
    char value;
};

#include "Tile.hpp"
#endif