#ifndef MAZE_HPP
#define MAZE_HPP

Maze::Maze(int nRow, int nCol)
{  
    std::vector<std::vector<Tile> > m(nRow, std::vector<Tile>(nCol, Tile()));
    matrix = m;
    actual_pos = matrix[0][0];
}

void Maze::fillMaze(std::string file_name)
{
    std::ifstream file(file_name);
    if(file) 
    {
        std::string s;
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[i].size(); j++){
                if(file.peek() != '\n'){
                    matrix[i][j] = Tile(file.get(), i, j);
                    if(matrix[i][j].getValue() == 'S'){
                        actual_pos = matrix[i][j];
                    }
                }
                else file.ignore(1);
            }
            if(file.peek() == '\n') file.ignore(1);
        }
        file.close();
    }
    else{
        std::cerr << "file opening failed\n";
        return;
    }
}

bool Maze::movePos(Position p)
{
    if(!matrix[actual_pos.getX() + p.getX()][actual_pos.getY() + p.getY()].isSolid()){
        Tile t = actual_pos;
        if((actual_pos.getX() + p.getX()) < matrix.size() && (actual_pos.getX() + p.getX()) >= 0)
        {
            actual_pos.setX(actual_pos.getX() + p.getX());
        }
        else return false;
        if((actual_pos.getY() + p.getY()) < matrix[0].size() && (actual_pos.getY() + p.getY()) >= 0)
        {
            actual_pos.setY(actual_pos.getY() + p.getY());
        }
        else return false;
        if(actual_pos.getPosition() != t.getPosition()){
            if(matrix[actual_pos.getX()][actual_pos.getY()].getValue() != 'E' && matrix[actual_pos.getX()][actual_pos.getY()].getValue() != 'S')
                matrix[actual_pos.getX()][actual_pos.getY()].setValue('X');
            else if(matrix[actual_pos.getX()][actual_pos.getY()].getValue() != 'S')
                actual_pos.setValue('E');
            if(matrix[t.getX()][t.getY()].getValue() != 'S' && matrix[t.getX()][t.getY()].getValue() != 'E'){
                matrix[t.getX()][t.getY()].setValue('+');
            }
            return true;
        }
        else return false;
    }
    else return false;
}

bool Maze::checkWallUp()
{
    if(matrix[actual_pos.getX()-1][actual_pos.getY()].isSolid()) return true;
    else return false;
}

bool Maze::checkWallDown()
{
    if(matrix[actual_pos.getX()+1][actual_pos.getY()].isSolid()) return true;
    else return false;
}

bool Maze::checkWallRight()
{
    if(matrix[actual_pos.getX()][actual_pos.getY()+1].isSolid()) return true;
    else return false;
}

bool Maze::checkWallLeft()
{
    if(matrix[actual_pos.getX()][actual_pos.getY()-1].isSolid()) return true;
    else return false;
}

Tile Maze::getPosAt(Position p)
{
    return matrix[p.getX()][p.getY()];
}

void Maze::printMaze()
{
    for(int i=0; i < matrix.size(); i++){
        for(int j=0; j < matrix[i].size(); j++){
            std::cout<<matrix[i][j];
        }
        std::cout<<"\n";
    }
    std::cout<<"Actual position: ["<<actual_pos.getX()<<"]["<<actual_pos.getY()<<"]\n";
}

#endif


/*
    if(!matrix[actual_pos.getX() + p.getX()][actual_pos.getY() + p.getY()].isSolid()){
        Tile t = actual_pos;
        if((actual_pos.getX() + p.getX()) < matrix.size())
        {
            actual_pos.setX(actual_pos.getX() + p.getX());
        }
        if((actual_pos.getY() + p.getY()) < matrix[0].size())
        {
            actual_pos.setY(actual_pos.getY() + p.getY());
        }
        matrix[actual_pos.getX()][actual_pos.getY()].setValue('X');
        if(matrix[t.getX()][t.getY()].getValue() != 'S'){
            matrix[t.getX()][t.getY()].setValue(' ');
        }
    }
*/

/*bool Maze::movePos(Position p)
{
    if(!matrix[p.getX()][p.getY()].isSolid()){
        Tile t = actual_pos;
        if((p.getX()) < matrix.size() && p.getX() >= 0)
        {
            actual_pos.setX(p.getX());
        }
        else return false;
        if((p.getY()) < matrix[0].size() && p.getY() >= 0)
        {
            actual_pos.setY(p.getY());
        }
        else return false;
        if(matrix[actual_pos.getX()][actual_pos.getY()].getValue() != 'E')
            matrix[actual_pos.getX()][actual_pos.getY()].setValue('X');
        else actual_pos.setValue('E');
        if(matrix[t.getX()][t.getY()].getValue() != 'S'){
            matrix[t.getX()][t.getY()].setValue(' ');
        }
        return true;
    }
    else return false;
}*/