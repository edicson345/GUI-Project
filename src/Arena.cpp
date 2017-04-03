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

        if(cells[x][y][z].isEmpty())
        {
            cells[x][y][z].placeUnit(new Actor(x,y,z, "BlackHat"));
            Object *o = cells[x][y][z].getUnit();
            blackHatList.push_back(static_cast<Actor*>(o));
        }
        else
        {
            x = rand() % dimensionX;
            y = rand() % dimensionY;
            z = rand() % dimensionZ;

            cells[x][y][z].placeUnit(new Actor(x,y,z, "BlackHat"));
            Object *o = cells[x][y][z].getUnit();
            whiteHatList.push_back(static_cast<Actor*>(o));
        }
    }

}

void Arena::placeWhiteHats(int numToPlace)
{
    whiteHats = numToPlace;
    int x,y,z;

    for(int i = 0; i < whiteHats; i++)
    {

        x = rand() % dimensionX;
        y = rand() % dimensionY;
        z = rand() % dimensionZ;

        if(cells[x][y][z].isEmpty())
        {
            cells[x][y][z].placeUnit(new Actor(x,y,z, "WhiteHat"));
            Object *o = cells[x][y][z].getUnit();
            whiteHatList.push_back(static_cast<Actor*>(o));
        }
        else
        {
            x = rand() % dimensionX;
            y = rand() % dimensionY;
            z = rand() % dimensionZ;

            cells[x][y][z].placeUnit(new Actor(x,y,z, "WhiteHat"));
            Object *o = cells[x][y][z].getUnit();
            whiteHatList.push_back(static_cast<Actor*>(o));
        }
    }
}

void Arena::printAllLocations()
{
    for(int i = 0; i < blackHatList.size(); i++)
        allActors.push_back(blackHatList[i]);
    for(int i = 0; i < whiteHatList.size(); i++)
        allActors.push_back(whiteHatList[i]);
    for(int i = 0; i < copList.size(); i++)
        allActors.push_back(copList[i]);

    std::random_shuffle(allActors.begin(), allActors.end());

    for(int i = 0; i < allActors.size(); i++)
        allActors[i]->getPosition();

}

void Arena::placeCops(int numToPlace)
{
    cops = numToPlace;
    int x,y,z;

    for(int i = 0; i < cops; i++)
    {
        x = rand() % dimensionX;
        y = rand() % dimensionY;
        z = rand() % dimensionZ;

        if(cells[x][y][z].isEmpty())
        {
            cells[x][y][z].placeUnit(new Actor(x,y,z, "Cop"));
            Object *o = cells[x][y][z].getUnit();
            copList.push_back(static_cast<Actor*>(o));
        }
        else
        {
            x = rand() % dimensionX;
            y = rand() % dimensionY;
            z = rand() % dimensionZ;

            cells[x][y][z].placeUnit(new Actor(x,y,z, "Cop"));
            Object *o = cells[x][y][z].getUnit();
            whiteHatList.push_back(static_cast<Actor*>(o));
        }

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
