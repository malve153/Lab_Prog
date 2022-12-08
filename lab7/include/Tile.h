#ifndef TILE_H
#define TILE_H
#include "Position.h"

class Tile : public Position{
public:
    Tile(char v = ' ', int posX = 0, int posY = 0);
    char getValue(){ return value;}
    void setValue(char c);
    bool isSolid();
    bool isExit();
    friend std::ostream& operator<<(std::ostream& os, Tile& t);
private:
    char value;
    bool solid;
};

#include "Tile.hpp"
#endif