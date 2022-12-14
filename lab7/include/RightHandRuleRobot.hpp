#ifndef RIGHTHANDRULEROBOT_HPP
#define RIGHTHANDRULEROBOT_HPP

#ifdef _WIN32
#  include <Windows.h>
#  define sleep_function         Sleep
#  define time_multiplier        1
#else
#  include <unistd.h>
#  define sleep_function         usleep
#  define time_multiplier        1000
#endif

void RightHandRuleRobot::turnL()
{
    turn--;
    if(direction == 'r') direction = 'u';
    else if(direction == 'u') direction = 'l';
    else if(direction == 'l') direction = 'd';
    else if(direction == 'd') direction = 'r';
    
}

void RightHandRuleRobot::turnR()
{
    turn++;
    if(direction == 'r') direction = 'd';
    else if(direction == 'd') direction = 'l';
    else if(direction == 'l') direction = 'u';
    else if(direction == 'u') direction = 'r';   
}

bool RightHandRuleRobot::freeL(Maze& m)
{
    if(direction == 'r') return !m.checkWallUp();
    else if(direction == 'u') return !m.checkWallLeft();
    else if(direction == 'l') return !m.checkWallDown();
    else if(direction == 'd') return !m.checkWallRight();
}

bool RightHandRuleRobot::freeR(Maze& m)
{
    if(direction == 'r') return !m.checkWallDown();
    else if(direction == 'd') return !m.checkWallLeft();
    else if(direction == 'l') return !m.checkWallUp();
    else if(direction == 'u') return !m.checkWallRight(); 
}

bool RightHandRuleRobot::moveForward(Maze& m)
{
    bool flag = false;
    if(direction == 'r')
    {
        flag = m.movePos(Position(0,1));
        pos = m.getActual_pos();
    }
    else if(direction == 'u')
    {
        flag = m.movePos(Position(-1,0));
        pos = m.getActual_pos();
    }
    else if(direction == 'l')
    {
        flag = m.movePos(Position(0,-1));
        pos = m.getActual_pos();
    }
    else if(direction == 'd')
    {
        flag = m.movePos(Position(1,0));
        pos = m.getActual_pos();
    }
    return flag;
}

void RightHandRuleRobot::move(Maze& m){
    while(!m.getActual_pos().isExit())
    {
        if(direction == 'r' && turn == 0){ //if direction and turn are setted to default value
            while (moveForward(m)); //moves forward untill it hits a wall
            if(freeR(m)) //if it can move right, turn right and move forward
            {
                turnR();
                moveForward(m);
            }
            else if(freeL(m)) //if it can move left, turn left and move forward
            {
                turnL();
                moveForward(m);
            }
            else{ //the only direction avaiable is down so it turns right 2 times and moves forward
                turnR();
                turnR();
                moveForward(m);
            }
        }
        else if(freeR(m))   //if direction and turn are not default and it can move left
        {                   //turn left and move forward
            turnR();
            moveForward(m);
        }
        else if( moveForward(m)){} //if direction and turn are not default and can move forward, do it
        else   //otherwise turn right and move forward
        {
            turnL();
            moveForward(m);
        }
        m.printMaze();
        sleep_function(time_multiplier * 300);
    }
    if(m.getActual_pos().isExit()) std::cout << "-------Il robot e' uscito-------\n";
}
#endif