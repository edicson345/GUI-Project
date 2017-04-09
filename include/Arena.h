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

    protected:

    private:
        std::vector<Actor*> allActors;
        std::queue<Actor*> runningQueue;
        int dimensionX, dimensionY, dimensionZ;
        std::vector<Actor*> blackHatList;
        std::vector<Actor*> whiteHatList;
        std::vector<Actor*> copList;
        static Arena* arena;
        Cell*** cells;
        int blackHats;
        int whiteHats;
        int cops;



};

#endif // ARENA_H
