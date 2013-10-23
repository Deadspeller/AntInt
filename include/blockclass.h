#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <time.h>

extern float xpos, ypos, zpos;
extern float colobjects[6][4];

struct blockstruct {
      int minx, maxx, minz, maxz;
    };
vector <blockstruct> blockvector;

class Block
{

public:
	int xposition, zposition, yposition;
	bool blockcreated;

void spawnBlock()
	{
		yposition = 0.1;

		if(fmod(zpos,2) > 1)	
			zposition = ceil(zpos+1)+1;
		else if(fmod(zpos,2) > 0)	
			zposition = floor(zpos+1)+1;
			
		if(fmod(xpos,2) > 1)	
			xposition = ceil(xpos+1)+1;
		else if(fmod(xpos,2) > 0)	
			xposition = floor(xpos+1)+1;

cout<<"Zeiger pos: "<<xpos<<" "<<zpos<<endl;
cout<<"Block created and spawned at: x="<<xposition<<" z="<<zposition<<endl;


//fill vector with data
blockvector.push_back(blockstruct());
cout<<"Block No: "<<blockvector.size()-1<<endl;
blockvector[blockvector.size()-1].minx = xposition-1;
blockvector[blockvector.size()-1].maxx = xposition+1;
blockvector[blockvector.size()-1].minz = zposition-1;
blockvector[blockvector.size()-1].maxz = zposition+1;

		blockcreated = true;
	}

void drawBlock()
{
		//draw the ant
		glPushMatrix();
		glTranslated(xposition, yposition, zposition);		

		glScalef(1,1,1);
		glColor3f(1,0.1,0.1);
	 
		// Block
		glBegin(GL_POLYGON);
		glColor3f(0, 0, 1);
		glVertex3f(-1, 1, -1);
		glVertex3f(1, 1, -1);
		glVertex3f(1, 1, 1);
		glVertex3f(-1, 1, 1);
		glEnd();

		glPopMatrix();

} //end blockplace


}; //end Class
