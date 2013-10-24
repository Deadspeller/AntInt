#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <time.h>

extern float xpos, ypos, zpos;
extern float colobjects[6][4];

struct blockstruct 
	{
		int blocktype; //1 = block, 2 = food
		int xposition, zposition;	
    	int minx, maxx, minz, maxz;
    };
vector <blockstruct> blockvector;
vector <vector <blockstruct> > blockvecvec(52, vector<blockstruct>(52));




class Block
{

public:
	int xposition, zposition, yposition;
	bool blockcreated;
	int blocktype = 1;

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

cout<<"Zeiger pos: "<<xpos<<" "<<zpos<<endl;
cout<<"Block created and spawned at: x="<<xposition<<" z="<<zposition<<endl;


//fill vector with data
blockvector.push_back(blockstruct());
//blockvector[blockvector.size()-1].xposition = xposition;
//blockvector[blockvector.size()-1].zposition = zposition;

blockvecvec[xposition][zposition].blocktype = typeblock;
/*blockvector[blockvector.size()-1].minx = xposition-1;
blockvector[blockvector.size()-1].maxx = xposition+1;
blockvector[blockvector.size()-1].minz = zposition-1;
blockvector[blockvector.size()-1].maxz = zposition+1;
*/
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
