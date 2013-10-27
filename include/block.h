#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <time.h>

extern float xpos, ypos, zpos;
extern float colobjects[6][4];


extern vector < vector <worldstruct> > worldvector;


class Block	//class for all classes, Wall-Blocks and Food-Blocks
{

public:
	int xposition, zposition, yposition;
	bool blockcreated;
	int blocktype;	// 1 = block, 2 = food

void spawnBlock(int typeblock)
	{
		blocktype = typeblock;
		yposition = 0.1;

		if(fmod(zpos,2) > 1)	
			zposition = ceil(zpos+1)+1;
		else if(fmod(zpos,2) > 0)	
			zposition = floor(zpos+1)+1;
			
		if(fmod(xpos,2) > 1)	
			xposition = ceil(xpos+1)+1;
		else if(fmod(xpos,2) > 0)	
			xposition = floor(xpos+1)+1;

		if(blocktype ==1)cout<<"Block created and spawned at: x="<<xposition<<" z="<<zposition<<endl;
	if(blocktype ==2)cout<<"Food created and spawned at: x="<<xposition<<" z="<<zposition<<endl;


		//fill vector with data

		worldvector[xposition][zposition].blocktype = typeblock;
		blockcreated = true;
	}

void drawBlock()
{
		//draw the ant
		glPushMatrix();
		glTranslated(xposition, yposition, zposition);		

		glScalef(1,1,1);
		
	 
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
