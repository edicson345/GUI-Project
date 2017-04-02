#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include <BlackHat.h>
#include <Actor.h>
#include <Cell.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Arena
{
    public:
        Arena();
        Arena(int x, int y, int z);
        void emptyArena();
        void placeBlackHats(int numToPlace);
        void placeWhiteHats(int numToPlace);
        void placeCops(int numToPlace);
        virtual ~Arena();

    protected:

    private:
        int dimensionX, dimensionY, dimensionZ;
        std::vector<Actor*> blackHatList;
        std::vector<Actor*> whiteHatList;
        std::vector<Actor*> copList;
        static Arena* arena;
        Cell*** cells;
        int blackHats;
        int whiteHats;
        int cops;
        int bakeries;

};

#endif // ARENA_H
