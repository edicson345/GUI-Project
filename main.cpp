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
    Arena *a = new Arena(10, 10, 10);
    a->placeBlackHats(0);
    a->placeWhiteHats(0);
    a->placeCops(1);

    int x, y, z;
    x = a->dimensionX;
    y = a->dimensionY;
    z = a->dimensionZ;
    int cnt = 0;


    while(cnt < 10)
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

    a->emptyArena();
}
