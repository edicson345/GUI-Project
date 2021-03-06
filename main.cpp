#include <iostream>
#include <Arena.h>
#include <Actor.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
    vector<Actor*> players;
    Arena *a = new Arena(500, 500, 10);
    a->placeBlackHats(3);
    a->placeWhiteHats(3);
    a->placeCops(3);

    int x, y, z;
    x = a->dimensionX;
    y = a->dimensionY;
    z = a->dimensionZ;
    int cnt = 0;


    while(cnt < 26 && !a->Gilberts.isOpen())
    {

    a->tick();



        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                for(int k = 0; k < z; k++)
                {
                    if(!a->cells[i][j][k].isEmpty())
                    {
                        players.push_back(a->cells[i][j][k].getUnit());
                    }
                }


    for(int i = 0; i < players.size(); i++)
    {
        int posx = players[i]->position[0];
        int posy = players[i]->position[1];
        int posz = players[i]->position[2];
        string type = players[i]->ID;
        cout << posx << " " << posy << " " << posz << " " << type << endl;
    }
    players.clear();
    cnt++;
    }

    if(!a->Gilberts.isOpen())
        cout << "WhiteHats win" << endl;
    else
        cout << "BlackHats win" << endl;
    a->emptyArena();
}
