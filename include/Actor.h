#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "Object.h"
#include <iostream>

using namespace std;

class Actor
{
    public:
        string ID;
        int position[3];
        void animate();
        void animateBlackHat(int xLimit, int yLimit, int zLimit);
        void animateWhiteHat(int xLimit, int yLimit, int zLimit);
        void animateCop(int xLimit, int yLimit, int zLimit);
        Actor();
        Actor(int x, int y, int z, string ID, int identifier);
        void animate(int xLimit, int yLimit, int zLimit);
        int* getPosition();
        void printPosition();
        void setPosition(int x, int y, int z);
        virtual ~Actor();
        bool outOfPlay = false;

    protected:

    private:
        int IDnum;//0 for blackhats 1 for whitehats 2 for cops

        static int cnt;


};

#endif // ACTOR_H
