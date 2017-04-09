#include "Actor.h"

Actor::Actor()
{
    position[0] = 0;
    position[1] = 0;
    position[2] = 0;
}

Actor::Actor(int x, int y, int z, string role, int identifier)
{
    position[0] = x;
    position[1] = y;
    position[2] = z;
    ID = role;
    IDnum = identifier;
}

int* Actor::getPosition()
{
    return position;
}

void Actor::printPosition()
{
    for(int i = 0; i < 3; i++)
        cout << position[i] << " ";

    cout << ID << endl;
}

void Actor::animate(int xLimit, int yLimit, int zLimit)
{
    switch(IDnum)
    {
        case 0:
            animateBlackHat(xLimit, yLimit, zLimit);
            break;
        case 1:
            animateWhiteHat(xLimit, yLimit, zLimit);
            break;
        case 2:
            animateCop(xLimit, yLimit, zLimit);
            break;
        default:
            break;
    }
}

void Actor::setPosition(int x, int y, int z)
{
    position[0] = x;
    position[1] = y;
    position[2] = z;
}

void Actor::animateBlackHat(int xLimit, int yLimit, int zLimit)
{

}

void Actor::animateWhiteHat(int xLimit, int yLimit, int zLimit)
{

}

void Actor::animateCop(int xLimit, int yLimit, int zLimit)
{

}

Actor::~Actor()
{
    //dtor
}
