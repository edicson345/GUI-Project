#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <Object.h>

class Cell
{
    public:
        Cell();
        Cell(int a, int b, Object* object);
        Cell(int a, int b);
        Object* getUnit();
        void placeUnit(Object* object);
        bool isEmpty();
        int getX();
        int getY();
        ~Cell();

    protected:

    private:
        int x, y;
        bool vacant;
        Object* unit;
};

#endif // CELL_H
