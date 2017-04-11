#ifndef ARENA_H
#define ARENA_H

#include <Bakery.h>
#include <vector>
#include <algorithm>
#include <BlackHat.h>
#include <Actor.h>
#include <Cell.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <queue>

using namespace std;

class Arena
{

    public:
        std::vector<Actor*> blackHatList;
        Bakery Gilberts;
        Arena();
        Arena(int x, int y, int z);
        void emptyArena();
        void placeBlackHats(int numToPlace);
        void placeWhiteHats(int numToPlace);
        void placeCops(int numToPlace);
        void tick();
        bool isSafe(int x, int y, int z);
        virtual ~Arena();
        int dimensionX, dimensionY, dimensionZ;
        Cell*** cells;
        std::vector<Actor*> copList;

    protected:

    private:
        std::vector<Actor*> allActors;
        std::queue<Actor*> runningQueue;
        void scan(int x, int y, int z);
        bool isSafe2d(int x, int y, int z);
        std::vector<Actor*> whiteHatList;

        static Arena* arena;

        int blackHats;
        int whiteHats;
        int cops;



};

#endif // ARENA_H
