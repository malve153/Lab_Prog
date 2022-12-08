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

void Maze::movePos(Position p)
{
    if(!matrix[p.getX()][p.getY()].isSolid()){
        Tile t = actual_pos;
        if((p.getX()) < matrix.size() && p.getX() >= 0)
        {
            actual_pos.setX(p.getX());
        }
        if((p.getY()) < matrix[0].size() && p.getY() >= 0)
        {
            actual_pos.setY(p.getY());
        }
        if(matrix[actual_pos.getX()][actual_pos.getY()].getValue() != 'E')
            matrix[actual_pos.getX()][actual_pos.getY()].setValue('X');
        else actual_pos.setValue('E');
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