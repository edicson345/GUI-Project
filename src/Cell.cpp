#include "Cell.h"

Cell::Cell()
{
    vacant = true;
    unit = 0;
}

bool Cell::isEmpty()
{
    return vacant;
}

void Cell::vacateCell()
{
    vacant = true;
    unit = 0;
}

void Cell::placeUnit(Actor* actor)
{
    if(actor != 0)
    {
        unit = actor;
        vacant = false;
    }
}

Actor* Cell::getUnit()
{
    return unit;
}

Cell::~Cell()
{

}
