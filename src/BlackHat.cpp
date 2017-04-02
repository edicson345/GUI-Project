#include "BlackHat.h"


BlackHat::BlackHat()
{
    name = " ";
    ID = ' ';
}

string BlackHat::getName() const
{
    return name;
}

void BlackHat::setID(char id)
{
    ID = id;
}

char BlackHat::getID() const
{
    return ID;
}


BlackHat::~BlackHat()
{

}
