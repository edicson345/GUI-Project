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

bool Arena::isSafe(int x, int y, int z)
{
    return (x >= 0 && x < dimensionX && y >= 0 && y < dimensionY && z >= 0 && z < dimensionZ && cells[x][y][z].isEmpty());
}

void Arena::placeBlackHats(int numToPlace)
{
    blackHats = numToPlace;
    srand(time(NULL));
    int x,y,z;

    for(int i = 0; i < blackHats; i++)
    {
        bool placed = false;
        while(!placed)
        {
            x = dimensionX - 1;
            y = rand() % dimensionY;
            z = rand() % dimensionZ;

            if(cells[x][y][z].isEmpty())
            {
                cells[x][y][z].placeUnit(new Actor(x,y,z, "BlackHat", 0));
                Actor *a = cells[x][y][z].getUnit();
                blackHatList.push_back(a);
                placed = true;
            }
        }
    }
}

void Arena::placeWhiteHats(int numToPlace)
{

    whiteHats = numToPlace;
    int x,y,z;

    for(int i = 0; i < whiteHats; i++)
    {
        bool placed = false;
        while(!placed)
        {
            x = rand() % dimensionX;
            y = rand() % dimensionY;
            z = rand() % dimensionZ;

            if(cells[x][y][z].isEmpty())
            {
                cells[x][y][z].placeUnit(new Actor(x,y,z, "WhiteHat", 1));
                Actor *a = cells[x][y][z].getUnit();
                whiteHatList.push_back(a);
                placed = true;
            }
        }
    }
}

void Arena::tick()
{
    int x, y, z;
    int x1, y1, z1;

    for(int i = 0; i < blackHatList.size(); i++)
        allActors.push_back(blackHatList[i]);
    for(int i = 0; i < whiteHatList.size(); i++)
        allActors.push_back(whiteHatList[i]);
    for(int i = 0; i < copList.size(); i++)
        allActors.push_back(copList[i]);

    std::random_shuffle(allActors.begin(), allActors.end());

    for(int i = 0; i < allActors.size(); i++)
    {
        bool moved = false;
        int chance;
        x = allActors[i]->position[0];
        y = allActors[i]->position[1];
        z = allActors[i]->position[2];
        x1 = x;
        y1 = y;
        z1 = z;

        if(allActors[i]->ID == "Cop")
        {
            while(!moved && chance < 20)
            {
                x += (rand() % 3) - 1;
                y += (rand() % 3) - 1;
                z += (rand() % 3) - 1;
                if((isSafe(x, y, z)))
                {
                    allActors[i]->printPosition();
                    cells[x1][y1][z1].vacateCell();
                    cells[x][y][z].placeUnit(allActors[i]);
                    allActors[i]->setPosition(x, y, z);
                    allActors[i]->printPosition();
                    moved = true;
                }
                else
                {
                    x = x1;
                    y = y1;
                    z = z1;
                    chance++;
                }
            }

        }
        else if(allActors[i]->ID == "BlackHat")
        {
            while(!moved && chance < 20)
            {
                x -= 1;
                y += (rand() % 3) - 1;
                z += (rand() % 3) - 1;
                if(x == 0 && (isSafe(dimensionX-1, y, z)) && cells[dimensionX-1][y][z].isEmpty())
                {
                    allActors[i]->printPosition();
                    cells[x1][y1][z].vacateCell();
                    cells[dimensionX-1][y][z].placeUnit(allActors[i]);
                    allActors[i]->setPosition(dimensionX-1, y, z);
                    allActors[i]->printPosition();
                    Gilberts.takeDamage(5);
                    moved = true;
                }
                else if(isSafe(x, y, z))
                {
                    allActors[i]->printPosition();
                    cells[x1][y1][z1].vacateCell();
                    cells[x][y][z].placeUnit(allActors[i]);
                    allActors[i]->setPosition(x, y, z);
                    allActors[i]->printPosition();
                    moved = true;
                }
                else
                {
                    x = x1;
                    y = y1;
                    z = z1;
                    chance++;
                }
            }
        }
        else if(allActors[i]->ID == "WhiteHat")
        {
            while(!moved && chance < 20)
            {
                x += (rand() % 3) - 1;
                y += (rand() % 3) - 1;
                z += (rand() % 3) - 1;
                if((isSafe(x, y, z)))
                {
                    allActors[i]->printPosition();
                    cells[x1][y1][z1].vacateCell();
                    cells[x][y][z].placeUnit(allActors[i]);
                    allActors[i]->setPosition(x, y, z);
                    allActors[i]->printPosition();
                    moved = true;
                }
                else
                {
                    x = x1;
                    y = y1;
                    z = z1;
                    chance++;
                }
            }
        }

    }
    Gilberts.outOfBusiness();
    allActors.clear();

}

void Arena::placeCops(int numToPlace)
{
    cops = numToPlace;
    int x,y,z;

    for(int i = 0; i < cops; i++)
    {
        bool placed = false;
        while(!placed)
        {
            x = rand() % dimensionX;
            y = rand() % dimensionY;
            z = rand() % dimensionZ;

            if(cells[x][y][z].isEmpty())
            {
                cells[x][y][z].placeUnit(new Actor(x,y,z, "Cop", 2));
                Actor *a = cells[x][y][z].getUnit();
                copList.push_back(a);
                placed = true;
            }
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
