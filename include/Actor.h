#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "Object.h"
#include <iostream>

using namespace std;

class Actor : public Object
{
    public:
        Actor();
        Actor(int x, int y, int z, string ID);
        void getPosition();
        virtual ~Actor();

    protected:

    private:
        int position[3];
        static int cnt;
        bool outOfPlay = false;
        string ID;
};

#endif // ACTOR_H
