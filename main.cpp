#include <iostream>
#include <Arena.h>

using namespace std;

int main()
{
    Arena *a = new Arena(10, 10, 10);
    a->placeBlackHats(3);
    a->placeWhiteHats(3);
    a->placeCops(3);
    a->printAllLocations();
    a->emptyArena();
}
