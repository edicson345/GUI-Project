#ifndef BAKERY_H
#define BAKERY_H

#include <iostream>

using namespace std;

class Bakery
{
    public:
        Bakery();
        bool isOpen();
        int getHP();
        void outOfBusiness();
        void takeDamage(int damage);
        virtual ~Bakery();

    protected:

    private:
        bool shutDown = false;
        int hitPoints = 40;
};

#endif // BAKERY_H
