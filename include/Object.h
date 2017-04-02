#ifndef OBJECT_H
#define OBJECT_H
#include <stdlib.h>
#include <time.h>
#include <Object.h>

class Object
{
    public:
        Object();
        Object(int x, int y);
        Object(int x, int y, Object*);
        Object* getObject();
        bool isEmpty();
        void setPosition(int x, int y);
        virtual void getPosition();
        void animate();
        virtual ~Object();

    protected:

    private:
        static int cnt;
        int position[2];
};

#endif // OBJECT_H
