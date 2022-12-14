#ifndef RANDOMROBOT_HPP
#define RANDOMROBOT_HPP

#ifdef _WIN32
#  include <Windows.h>
#  define sleep_function         Sleep
#  define time_multiplier        1
#else
#  include <unistd.h>
#  define sleep_function         usleep
#  define time_multiplier        1000
#endif

void RandomRobot::move(Maze& m)
{
    int c=0;
    while(!m.getActual_pos().isExit())
    {
        m.movePos(Position(rand() %3-1,rand() %3-1));
        pos = m.getActual_pos();
        if(c%100 == 0){
            m.printMaze();
            sleep_function(time_multiplier * 300);
        }
        c++;
    }
    m.printMaze();
    std::cout<< "EXIT FOUND IN "<<c<<" STEPS\n";
}

#endif