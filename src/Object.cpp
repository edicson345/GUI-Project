#include "Object.h"


Object::Object()
{

}

Object::Object(int x, int y)
{
    position[0] = x;
    position[1] = y;
}

void Object::getPosition()
{

}

void Object::setPosition(int x, int y)
{
    position[0] = x;
    position[1] = y;
}

void Object::animate()
{
    srand(time(NULL));

    int direction = rand() % 4 + 1;

    switch(direction)
    {
        case 0:
            position[0]++;
            break;
        case 1:
            position[0]--;
            break;
        case 2:
            position[1]++;
            break;
        case 3:
            position[1]--;
            break;
        default:
            break;
    }
}

Object::~Object()
{
    //dtor
}
