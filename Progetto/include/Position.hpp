#ifndef POSITION_HPP
#define POSITION_HPP

bool Position::operator==(const Position& p)
{
    if(this->getRow() == p.row && this->getCol() == p.col )
        return true;
    else return false;
}

bool Position::operator!=(const Position& p)
{
    if(this->getRow() == p.row && this->getCol() == p.col)
        return false;
    else return true;
}

std::ostream& operator<<(std::ostream& os, Position& p){
    return os<< '[' << p.row << "][" << p.col << "]\n";
}

#endif