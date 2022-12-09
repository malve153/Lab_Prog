#ifndef POSITION_HPP
#define POSITION_HPP

Position::Position(int posX, int posY)
{
    x = posX;
    y = posY;
}

bool Position::operator==(const Position& p){
    if(this->getX() == p.x && this->getY() == p.y)   
        return true;
    else return false;
}

bool Position::operator!=(const Position& p){
    if(this->getX() == p.x && this->getY() == p.y)   
        return false;
    else return true;
}
#endif