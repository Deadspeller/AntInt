/* World-Header File for main.cpp */


#include <GL/glew.h> // Include the GLEW header file  
#include "texture.h"


void world()	//Draw the world
{

    	glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, tex_ground[0]);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    	glColor3f(1,1,1); // If you do not set a color, the textured area will appear black.

    	glBegin(GL_POLYGON); //ground
    	glTexCoord2d(0,0);  glVertex3f(1, 0, 1);
    	glTexCoord2d(25,0);  glVertex3f(1, 0, 51);
    	glTexCoord2d(25,25);  glVertex3f(51, 0, 51);
    	glTexCoord2d(0,25);  glVertex3f(51, 0, 1);
    	glEnd();
    	glDisable(GL_TEXTURE_2D);

glBegin(GL_POLYGON); //hinderniss1
	glColor3f(0,0,1);
	glVertex3f(10, 0.2, 5);
	glVertex3f(10, 0.2, 7);
	glVertex3f(20, 0.2, 7);
	glVertex3f(20, 0.2, 5);
    	glEnd();

glBegin(GL_POLYGON); //hinderniss2
	glColor3f(0,0,1);
	glVertex3f(30, 0.2, 5);
	glVertex3f(30, 0.2, 25);
	glVertex3f(35, 0.2, 25);
	glVertex3f(35, 0.2, 5);
    	glEnd();


glBegin(GL_POLYGON); //wall1
	glColor3f(0.9,1,1);
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, 51);
	glVertex3f(1, 51, 51);
	glVertex3f(1, 51, 1);
    	glEnd();

glBegin(GL_POLYGON); //wall2
	glColor3f(1,0.9,1);
	glVertex3f(1, 0, 1);
	glVertex3f(51, 0, 1);
	glVertex3f(51, 50, 1);
	glVertex3f(1, 50, 1);
    	glEnd();

glBegin(GL_POLYGON); //wall3
	glColor3f(1,1,0.9);
	glVertex3f(51, 0, 1);
	glVertex3f(51, 0, 51);
	glVertex3f(51, 50, 51);
	glVertex3f(51, 50, 1);
    	glEnd();

glBegin(GL_POLYGON); //wall4
	glColor3f(0.9,0.9,1);
	glVertex3f(1, 0, 51);
	glVertex3f(51, 0, 51);
	glVertex3f(51, 50, 51);
	glVertex3f(1, 50, 51);
    	glEnd();

glBegin(GL_POLYGON); //top
	glColor3f(1,1,1);
	glVertex3f(1, 50, 1);
	glVertex3f(51, 50, 1);
	glVertex3f(51, 50, 51);
	glVertex3f(1, 50, 51);
    	glEnd();
}

