#ifndef ROBOT_HPP
#define ROBOT_HPP

Robot::Robot(Tile mazePos)
    : pos{mazePos.getPosition()}{}

void Robot::move(Position p)
{
    pos.setX(pos.getX() + p.getX());
    pos.setY(pos.getY() + p.getY());
}

#endif