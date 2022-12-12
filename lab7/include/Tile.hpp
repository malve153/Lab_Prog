#ifndef TILE_HPP
#define TILE_HPP

Tile::Tile(char v, int posX, int posY) 
    : Position(posX,posY)
{
        if(v == '*' || v == ' ' || v == 'E' || v == 'S') value = v;
        else value = '*';
        if(value == '*') solid = true;
        else solid = false;
}

// '*'=wall, ' '=empy tile, 'E'=exit, 'S'=start, 'X'=current position, 
// '+'=robot has already been here
void Tile::setValue(char c)
{
    if(c == '*' || c == ' ' || c == 'E' || c == 'S' || c == 'X' || c== '+') value = c;
}

bool Tile::isSolid()
{
    if(solid) return true;
    else return false;
}

bool Tile::isExit()
{
    if(value == 'E') return true;
    else return false;
}

std::ostream& operator<<(std::ostream& os, Tile& t){
    return os<< t.value;
}

#endif