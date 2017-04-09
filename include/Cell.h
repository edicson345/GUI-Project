#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <Actor.h>

class Cell
{
    public:
        Cell();
        Actor* getUnit();
        void placeUnit(Actor* actor);
        void vacateCell();
        bool isEmpty();
        ~Cell();

    protected:

    private:
        bool vacant = true;
        Actor* unit;
};

#endif // CELL_H
