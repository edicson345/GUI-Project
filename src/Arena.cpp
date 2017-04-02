#include "Arena.h"

Arena::Arena()
{

}

Arena::Arena(int x, int y, int z)
{
    dimensionX = x;
    dimensionY = y;
    dimensionZ = z;

    cells = new Cell**[dimensionX];

    for(int i = 0; i < dimensionX; i++)
    {
        cells[i] = new Cell*[dimensionY];
        for(int j = 0; j < dimensionY; j++)
        {
            cells[i][j] = new Cell[dimensionZ];
        }
    }
}

void Arena::placeBlackHats(int numToPlace)
{
    blackHats = numToPlace;
    srand(time(NULL));
    int x,y,z;

    for(int i = 0; i < blackHats; i++)
    {
        x = rand() % dimensionX;
        y = rand() % dimensionY;
        z = rand() % dimensionZ;

        cells[x][y][z].placeUnit(new Actor(x,y,z, "BlackHat"));
        Object *o = cells[x][y][z].getUnit();
        static_cast<Actor*>(o)->getPosition();
    }

}

void Arena::emptyArena()
{
    for(int i = 0; i < dimensionX; i++)
    {
        for(int j = 0; j < dimensionY; j++)
            delete [] cells[i][j];

        delete [] cells[i];
    }

    delete [] cells;

    cout << "Arena is now clear." << endl;
}

Arena::~Arena()
{
    //dtor
}
