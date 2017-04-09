#include "Bakery.h"

Bakery::Bakery()
{
    //ctor
}

int Bakery::getHP()
{
    return hitPoints;
}

bool Bakery::isOpen()
{
    return shutDown;
}

void Bakery::takeDamage(int damage)
{
    hitPoints -= damage;
    cout << "Bakery HP: " << hitPoints << endl;
}

void Bakery::outOfBusiness()
{
    if(hitPoints < 0)
        shutDown = true;
}

Bakery::~Bakery()
{
    //dtor
}
