#ifndef TILE_H
#define TILE_H
#include "Position.h"

//class that inherits all public members from Position 
//and adds a character that defines the type of the tile
class Tile : public Position{
public:
    Tile(char v = ' ', int posX = 0, int posY = 0);
    char getValue(){ return value;}
    void setValue(char c);
    bool isSolid(); //check if the tile is a wall(*)
    bool isExit(); //check if the tile is an exit(E)
    friend std::ostream& operator<<(std::ostream& os, Tile& t);
private:
    char value;
    bool solid;
};

#include "Tile.hpp"
#endif