/* World-Header File for main.cpp */


#include <GL/glew.h> // Include the GLEW header file  


extern vector < vector <worldstruct> > worldvector;
extern int xworldsize, zworldsize;

void world()	//Draw the world
{
	//setting up the "walls"
	for(int i =1; i<=zworldsize; i++)
	{
		worldvector[i][0].blocktype=1;
	}
	for(int i =1; i<=xworldsize; i++)
	{
		worldvector[0][i].blocktype=1;
	}
	for(int i =1; i<=zworldsize; i++)
	{
		worldvector[i][xworldsize+1].blocktype=1;
	}
	for(int i =1; i<=xworldsize; i++)
	{
		worldvector[zworldsize+1][i].blocktype=1;
	}

	
	//Draw the Walls
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_ground[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1,1,1); // If you do not set a color, the textured area will appear black.
	glBegin(GL_POLYGON); //ground
	glTexCoord2d(0,0);  glVertex3f(0.5, 0, 0.5);
	glTexCoord2d(xworldsize+1,0);  glVertex3f(0.5, 0, xworldsize+0.5);
	glTexCoord2d(xworldsize+1,zworldsize+1);  glVertex3f(zworldsize+0.5, 0, xworldsize+0.5);
	glTexCoord2d(0,zworldsize+1);  glVertex3f(zworldsize+0.5, 0, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);



	glBegin(GL_POLYGON); //wall1
	glColor3f(0.9,1,1);
	glVertex3f(0.5, 0, 0.5);
	glVertex3f(0.5, 0, xworldsize+0.5);
	glVertex3f(0.5, 30, xworldsize+0.5);
	glVertex3f(0.5, 30, 0.5);
	glEnd();

	glBegin(GL_POLYGON); //wall2
	glColor3f(1,0.9,1);
	glVertex3f(0.5, 0, 0.5);
	glVertex3f(zworldsize+0.5, 0, 0.5);
	glVertex3f(zworldsize+0.5, 30, 0.5);
	glVertex3f(0.5, 30, 0.5);
	glEnd();

	glBegin(GL_POLYGON); //wall3
	glColor3f(1,1,0.9);
	glVertex3f(zworldsize+0.5, 0, 0.5);
	glVertex3f(zworldsize+0.5, 0, xworldsize+0.5);
	glVertex3f(zworldsize+0.5, 30, xworldsize+0.5);
	glVertex3f(zworldsize+0.5, 30, 0.5);
	glEnd();

	glBegin(GL_POLYGON); //wall4
	glColor3f(0.9,0.9,1);
	glVertex3f(0.5, 0, xworldsize+0.5);
	glVertex3f(zworldsize+0.5, 0, xworldsize+0.5);
	glVertex3f(zworldsize+0.5, 30, xworldsize+0.5);
	glVertex3f(0.5, 30, xworldsize+0.5);
	glEnd();

	glBegin(GL_POLYGON); //top
	glColor3f(1,1,1);
	glVertex3f(0.5, 30, 0.5);
	glVertex3f(zworldsize+0.5, 30, 0.5);
	glVertex3f(zworldsize+0.5, 30, xworldsize+0.5);
	glVertex3f(0.5, 30, xworldsize+0.5);
	glEnd();
}

