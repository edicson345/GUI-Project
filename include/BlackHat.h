#ifndef BLACKHAT_H
#define BLACKHAT_H

#include <string>
#include <Cell.h>
#include <iostream>

using namespace std;

class BlackHat
{
    public:
        BlackHat();
        //BlackHat(string s, char id);
        string getName() const;
        char getID() const;
        void setID(char id);

        ~BlackHat();

    private:
        string name;
        char ID;
};

#endif // BLACKHAT_H
