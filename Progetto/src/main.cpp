#include "Tile.h"
#include <iostream>
int main()
{

    Tile t('C','B',4);
    std::cout << t;
    Position p = (Position) t;
    std::cout << p;
    return 0;
}