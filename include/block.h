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
struct worldstruct 
	{
		int blocktype; //1 = block, 2 = food, 3 = ant, 4 = enemy
	};

extern vector < vector <worldstruct> > worldvector;

class Block	//class for all classes, Wall-Blocks and Food-Blocks
{

public:
	float xposition, zposition, yposition;
	bool blockcreated;
	int blocktype;	// 1 = block, 2 = food

void spawnBlock(int typeblock)
	{
		blocktype = typeblock;
		yposition = 0;


			zposition = round(zpos+1);
			xposition = round(xpos+1);


		if(blocktype ==1)cout<<"Block created and spawned at: x="<<xposition<<" z="<<zposition<<endl;
	if(blocktype ==2)cout<<"Food created and spawned at: x="<<xposition<<" z="<<zposition<<endl;

		//fill vector with data
		worldvector[xposition][zposition].blocktype = typeblock;
		cout<<worldvector[xposition][zposition].blocktype<<endl;
		blockcreated = true;
	}

void drawBlock()
{
		//draw the ant
		glPushMatrix();
		glTranslated(xposition, yposition, zposition);		

		glScalef(0.5,0.5,0.5);
		
	 
		// Block
		glBegin(GL_POLYGON);
		if(blocktype == 1)
			glColor3f(0,0,1);
		else
			glColor3f(1,1,0);
		glVertex3f(-1, 1, -1);
		glVertex3f(1, 1, -1);
		glVertex3f(1, 1, 1);
		glVertex3f(-1, 1, 1);
		glEnd();

		glPopMatrix();
} //end blockplace


}; //end Class
