#include <iostream>
#include <Arena.h>

using namespace std;

int main()
{
    Arena *a = new Arena(3,3,3);
    a->placeBlackHats(3);
    a->emptyArena();
}
