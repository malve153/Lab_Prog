#ifndef POSITION_HPP
#define POSITION_HPP

Position::Position(int posX, int posY)
{
    if(x>=0 && x<9) x = posX;
    else x = 0;
    if(y>=0 && y<9) y = posY;
    else y = 0;
}

void Position::setPosition(int posX, int posY)
{
    x = posX;
    y = posY;
}

#endif