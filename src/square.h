#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

#include "ant.h"

extern float colobjects[6][4];

using namespace std;

class Square
{

public:
    int blockType;	// 0 = none, 1 = block, 2 = food
    int food;
    int smell;
//    Ant* ant;

    Square();
    Square(int typeblock, float xposi, float zposi);
};

#endif
