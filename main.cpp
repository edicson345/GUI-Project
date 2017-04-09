#include <iostream>
#include <Arena.h>

using namespace std;

int main()
{
    Arena *a = new Arena(10, 10, 10);
    a->placeBlackHats(3);
    a->placeWhiteHats(3);
    a->placeCops(3);
    for(int n = 0; n < 1000; n++)
        a->tick();

    if(!a->Gilberts.isOpen())
        cout << "WhiteHats win" << endl;
    else
        cout << "BlackHats win" << endl;
    a->emptyArena();
}
