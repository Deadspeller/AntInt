#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "ant.h"

extern float colobjects[6][4];

class Square	//class for all classes, Wall-Blocks and Food-Blocks
{

public:
    int blockType;	// 0 = none, 1 = block, 2 = food
    int food;
    int smell;
    Ant* ant;

    Square(int typeblock, float xposi, float zposi)
	{
		blockType = typeblock;		
	}

    Square()
    {}

}; //end Class

#endif
