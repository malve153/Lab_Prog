#ifndef TILE_HPP
#define TILE_HPP

Tile::Tile(char v, char posX, int posY) 
{
    if((posX >= 'A' && posX <= 'N') && (posY > 0 && posY < 13)){
        this->setRow(posX);
        this->setCol(posY);
    }      
    else{
        this->setRow('A');
        this->setCol(0);
    }
    value = v;
}

void Tile::setValue(char c)
{
    value = c;
}

std::ostream& operator<<(std::ostream& os, Tile& t){
    return os<< t.value;
}

#endif