#ifndef SQUARE_H
#define SQUARE_H

#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

extern float xpos, ypos, zpos;
extern float colobjects[6][4];
//struct Square
//	{
//		int blocktype; //1 = block, 2 = food, 3 = ant, 4 = enemy
//	};

//extern vector < vector <Square> > worldvector;

class Square	//class for all classes, Wall-Blocks and Food-Blocks
{

public:
//	float xBlockPosition, yBlockPosition, zBlockPosition;
	int blockType;	// 0 = none, 1 = block, 2 = food

    Square(int typeblock, float xposi, float zposi)
	{
		blockType = typeblock;
			
//		xBlockPosition = round(xposi);
//		yBlockPosition = 0.1;
//		zBlockPosition = round(zposi);
	}

    Square()
    {}

}; //end Class

#endif
