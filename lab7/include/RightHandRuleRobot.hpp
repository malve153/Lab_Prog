#ifndef RIGHTHANDRULEROBOT_HPP
#define RIGHTHANDRULEROBOT_HPP

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
        if(direction == 'r' && turn == 0){
            while (moveForward(m));
            if(freeR(m))
            {
                turnR();
                moveForward(m);
            }
            else if(freeL(m))
            {
                turnL();
                moveForward(m);
            }
            else{
                turnR();
                turnR();
                moveForward(m);
            }
        }
        else if(freeL(m))
        {
            turnL();
            moveForward(m);
        }
        else if( moveForward(m)){}
        else 
        {
            turnR();
            moveForward(m);
        }
    }
}
#endif