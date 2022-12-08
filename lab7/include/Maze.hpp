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
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[i].size(); j++){
                if(file.peek() != '\n'){
                    matrix[i][j] = Tile(file.get(), i, j);
                    if(matrix[i][j].getValue() == 'S'){
                        actual_pos = matrix[i][j];
                    }
                }
                else file.get();
            }
            if(file.peek() == '\n') file.get();
        }
    }
    else{
        std::cout << "file opening failed\n";
        return;
    }
}

void Maze::movePos(int x, int y)
{
    if(!matrix[actual_pos.getX() + x][actual_pos.getY() + y].isSolid()){
        Tile t = actual_pos;
        if((actual_pos.getX() + x) < matrix.size())
        {
            actual_pos.setX(actual_pos.getX() + x);
        }
        if((actual_pos.getY() + y) < matrix[0].size())
        {
            actual_pos.setY(actual_pos.getY() + y);
        }
        matrix[actual_pos.getX()][actual_pos.getY()].setValue('X');
        if(matrix[t.getX()][t.getY()].getValue() != 'S'){
            matrix[t.getX()][t.getY()].setValue(' ');
        }
    }
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