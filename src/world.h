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


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_grass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1,1,1); // If you do not set a color, the textured area will appear black.
	glBegin(GL_POLYGON); //ground
	glTexCoord2d(0,0);  glVertex3f(0.5, 0, 0.5);
	glTexCoord2d(xworldsize,0);  glVertex3f(0.5, 0, xworldsize+0.5);
	glTexCoord2d(xworldsize,zworldsize);  glVertex3f(zworldsize+0.5, 0, xworldsize+0.5);
	glTexCoord2d(0,zworldsize);  glVertex3f(zworldsize+0.5, 0, 0.5);
	glEnd();
		glDisable(GL_TEXTURE_2D);

}

