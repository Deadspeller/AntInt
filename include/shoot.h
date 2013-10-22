/* World-Header File for main.cpp */


#include <GL/glew.h> // Include the GLEW header file  
#include <vector> 
#include <iostream>
using namespace std;

extern float camheight;
extern float bulletspeed;
extern float bulletpos;
extern float xpos, zpos;
extern float yrot, xrot;
extern int bullets;



class Bulletclass
{
public:
float difTime, gesTime;
float xspeed, zspeed, yspeed;
float xdif, zdif, ydif;
bool bulletcreated, bulletflying;
float yorigin, zorigin, xorigin;	
float yrotradbullet, zrotradbullet, xrotradbullet;	

Timer shoottimer1;
void bulletmove()
{
	if(bulletcreated)
	{ 
		bulletflying = 1;
		yspeed -= 9.81 * difTime;		
	
		xdif += xspeed * difTime;
		zdif += zspeed * difTime;
		ydif += yspeed * difTime;

if(yorigin+ydif < 0.5 && yspeed < 0) 
{
yspeed = yspeed * -0.7;
}
		glPushMatrix();
		glTranslated(xorigin+xdif,yorigin+ydif,zorigin+zdif);
		glScalef(0.2,0.2,0.2);
		glColor3f(1,0,0);
    
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 0, 1);
		glVertex3f(0, 0, 1);
		glEnd();
		 
		// Purple side - RIGHT
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, 1, 1);
		glVertex3f(1, 0, 1);
		glEnd();
		 
		// Green side - LEFT
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 1, 1);
		glVertex3f(0, 0, 1);
		glEnd();
		 
		// Blue side - TOP
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, 1, 1);
		glVertex3f(0, 1, 1);
		glEnd();
		 
		// Red side - BOTTOM
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(1, 0, 1);
		glVertex3f(1, 1, 1);
		glVertex3f(0, 1, 1);
		glVertex3f(0, 0, 1);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glEnd();
           
           	glEnd();

		glPopMatrix();

			shoottimer1.stop();
			difTime = shoottimer1.getElapsedTimeInSec();
			if(difTime > 0.1) difTime = 0;	//remove first time
			gesTime += difTime;
			shoottimer1.start();
}
if(gesTime >= 5)
{
	bulletcreated = 0;
 	bulletflying = 0;
}

}

void bulletinit()
{
if(bulletflying == 0)
{
	bulletcreated = true;
	gesTime = 0;
	xdif = 0;
	zdif = 0;
	ydif = 0;

	xrotradbullet = (xrot / 180 * 3.141592654f); 
	yrotradbullet = (yrot / 180 * 3.141592654f);

		yorigin = ypos;
		zorigin = zpos;
		xorigin = xpos;	



if(sin(xrotradbullet)>0){xspeed = float(sin(yrotradbullet)-(sin(xrotradbullet)*sin(yrotradbullet)))*bulletspeed;
}

if(sin(xrotradbullet)<0){ xspeed = float(sin(yrotradbullet)+(sin(xrotradbullet)*sin(yrotradbullet)))*bulletspeed;
}

if(sin(xrotradbullet)>0) zspeed = -float(cos(yrotradbullet)-(sin(xrotradbullet)*cos(yrotradbullet)))*bulletspeed;

if(sin(xrotradbullet)<0) zspeed = -float(cos(yrotradbullet)+(sin(xrotradbullet)*cos(yrotradbullet)))*bulletspeed;

yspeed = (float(sin(xrotradbullet))*-bulletspeed);

}
}

};



Bulletclass bulletarray[10];

void Bullethandler(string action)
{
	if(action == "move")	//move the existing Bullets
	{	
		for(int movecounter = 0; movecounter<bullets; movecounter++)
		{
			if(bulletarray[movecounter].bulletcreated == 1) 
			{
			bulletarray[movecounter].bulletmove();
			
			}
		}	
	}

	if(action == "handle")	//create new Bullet
	{	
	
		for(int handlecounter=0; handlecounter<bullets; handlecounter++)
		{
			if(bulletarray[handlecounter].bulletflying == 0)
			{
			bulletarray[handlecounter].bulletinit();
			handlecounter = bullets;
			}			
		}

			
	}
}

