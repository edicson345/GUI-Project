#include "Actor.h"

Actor::Actor()
{
    position[0] = 0;
    position[1] = 0;
    position[2] = 0;
}

Actor::Actor(int x, int y, int z, string role)
{
    position[0] = x;
    position[1] = y;
    position[2] = z;
    ID = role;
}

void Actor::getPosition()
{
    for(int i = 0; i < 3; i++)
        cout << position[i] << " ";

    cout << endl;
}

Actor::~Actor()
{
    //dtor
}
