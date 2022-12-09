#ifndef RANDOMROBOT_HPP
#define RANDOMROBOT_HPP

void RandomRobot::move(Maze& m)
{
    int c=0;
    while(!m.getActual_pos().isExit())
    {
        m.movePos(Position(rand() %3-1,rand() %3-1));
        pos = m.getActual_pos();
        c++;
    }
    std::cout<< "Exit found in "<<c<<" steps\n";
}

#endif