#include "Cell.h"

Cell::Cell()
{
    vacant = true;
    x = 0;
    y = 0;
    unit = 0;
}

Cell::Cell(int a, int b)
{
    vacant = true;
    x = a;
    y = b;
}

Cell::Cell(int a, int b, Object* object)
{
    vacant = false;
    x = a;
    y = b;
    unit = object;
}

bool Cell::isEmpty()
{
    return vacant;
}

int Cell::getX()
{
    return x;
}

int Cell::getY()
{
    return y;
}

void Cell::placeUnit(Object* object)
{
    if(object != 0)
    {
        unit = object;
        unit->setPosition(x, y);
        vacant = false;
    }
}

Object* Cell::getUnit()
{
    return unit;
}

Cell::~Cell()
{

}
