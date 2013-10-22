#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <time.h>

//extern  sf::RenderWindow DSWindow;

extern float antspeed;
extern float xpos, ypos, zpos;
extern float colobjects[6][4];

using namespace std;

void shootcollision();
void impactdraw(char);

class Ant
{
	public:
	bool xcollision = false, zcollision = false;
	float difTime, gesTime;
	float xspeed, zspeed, yspeed;
	float xdif, zdif, ydif;
	float xdimension =3, zdimension =2;
	bool antalive;
	float yorigin, zorigin, xorigin;
	

	void main()
	{

	//antmove(2);
		if(!xcollision && !zcollision)
			antmove(2);
		if(xcollision)
			antmove(3);
		else if(zcollision)
			antmove(1);
		
		antcollision();
/*
	if(xcollision)	//bei kollision um 180° drehen
	{
			if(xspeed>0)xdif -= 0.1;
			else xdif += 0.1;
			xspeed *= -1;
		
		xcollision = false;
	}

	if(zcollision)	//bei kollision um 180° drehen
	{
			if(zspeed>0)zdif -= 0.1;
			else zdif += 0.1;
			zspeed *= -1;
			
		
		zcollision = false;
	}*/

		/*if(gesTime >= 3)
		{
			xspeed = 0;
			zspeed = 1;
		}
		if(gesTime >= 6)
		{
			xspeed = -1;
			zspeed = 0;
		}
		if(gesTime >= 9)
		{
			xspeed = 0;
			zspeed = -1;
		}
		if(gesTime >= 12)
		{
			xspeed = 1;
			zspeed = 0;
			gesTime = 0;
		}*/

	}


	Timer shoottimer1;
	void antmove(int a)	//move the ant
	{
		if(antalive)	//if the ant is alive
		{ 	
			if(gesTime >= 1)
			{
			switch(a)
			{
				case 1:	//vor
						xdif += 0.4;
						break;
				case 2:	//zurück
						xdif -= 0.4;
						break;
				case 3:	//rechts
						zdif += 0.4;
						break;
				case 4:	//links
						zdif -= 0.4;
						break;
			}
			gesTime = 0;
			}

			//cout<<"move xspeed= "<<xspeed<<endl;
			//move the ant
			/*xdif += xspeed * antspeed * difTime;
			zdif += zspeed * antspeed * difTime;
			ydif += yspeed * antspeed * difTime;
*/

			//draw the ant
			glPushMatrix();
			//glTranslated(2,10,0);
			glTranslated(xorigin+xdif, yorigin+ydif, zorigin+zdif);		

			//if(xspeed<0) glRotatef(180,0.0,1.0,0.0);	//backwards			
			//if(zspeed>0) glRotatef(-90,0.0,1.0,0.0);	//right
			//if(zspeed<0) glRotatef(90,0.0,1.0,0.0);		//left
			//glRotatef(asin(xspeed),0.0,1.0,0.0);
			if(zspeed) glRotatef(-asin(zspeed)*180/3.14,0.0,1.0,0.0);
			else if(xspeed) glRotatef(-asin(xspeed)*180/3.14,0.0,1.0,0.0);
			else glRotatef(90,0.0,1.0,0.0);	
switch(a)
			{
				case 1:	//vor
						glRotatef(-90,0.0,1.0,0.0);
						break;
				case 2:	//zurück
						glRotatef(90,0.0,1.0,0.0);
						break;
				case 3:	//rechts
						glRotatef(180,0.0,1.0,0.0);
						break;
				case 4:	//links
						glRotatef(0,0.0,1.0,0.0);
						break;
			}	
	
			//glRotatef(90,0.0,1.0,0.0);
			//glRotatef(zspeed*90,0.0,1.0,0.0);

			glScalef(0.5,0.5,0.5);
			glColor3f(1,0.1,0.1);
		 
			// Body
			glBegin(GL_POLYGON);
			glColor3f(1, 0, 0);
			glVertex3f(-1, 1, -1);
			glVertex3f(1, 1, -1);
			glVertex3f(1, 1, 1);
			glVertex3f(-1, 1, 1);
			glEnd();
			 
			// Head
			glBegin(GL_POLYGON);
			glColor3f(1, 0, 0);
			glVertex3f(1, 1, -0.3);
			glVertex3f(2, 1, -0.3);
			glVertex3f(2, 1, 0.3);
			glVertex3f(1, 1, 0.3);
			glEnd();

			glEnd();
			glPopMatrix();



				shoottimer1.stop();
				difTime = shoottimer1.getElapsedTimeInSec();
				if(difTime > 0.1) difTime = 0;	//remove first time
				gesTime += difTime;
				shoottimer1.start();
		}
	} //endif antmove



	void antcollision()
	{
		for(int i=0; i<6; i++)
		{
			if(xorigin+xdif+1.2 > colobjects[i][0] && xorigin+xdif-1.2 < colobjects[i][1])
			{
				if(zorigin+zdif+1.2 > colobjects[i][2] && zorigin+zdif-1.2 < colobjects[i][3])
				{
float xlinks, xrechts, zunten, zoben;
xlinks = abs(colobjects[i][0] - (xorigin+xdif+1.2));
xrechts = abs(xorigin+xdif+1.2 - (colobjects[i][1]));

zunten = abs(colobjects[i][2] - (zorigin+zdif+1.2));
zoben = abs(zorigin+zdif+1.2 - (colobjects[i][3]));


if(zunten <0.5 || zoben <0.5)
	zcollision = true;
if(xlinks <0.5 || xrechts <0.5)
	xcollision = true;
/*
					if(((xorigin+xdif+1.2 - colobjects[i][0]) < 0.1 ) || ((xorigin+xdif-1.2 - colobjects[i][1]) < 0.1 ))
					{
						xcollision = true;
						cout<<"xcollision"<<endl;
						//xdif -= xspeed*0.01;
					}
					if(((zorigin+zdif+1.2 - colobjects[i][2]) < 0.1 ) || ((zorigin+zdif-1.2 - colobjects[i][3]) < 0.1 ))
					{
						zcollision = true;
						cout<<"zcollision"<<endl;
						//zdif -= zspeed*0.01;
					}*/
					
				}
			}
		}
		
	
	}//endif antcollision



	void antspawn()	//spawn a new ant
	{
		
		if(antalive == 0)	//if ant is not already alive
		{
			
			antalive = true;
			gesTime = 0;
			xdif = 0;
			zdif = 0;
			ydif = 0;
			xspeed = -1;
			yspeed = 0;
			zspeed = 0;

			yorigin = 1;
			zorigin = zpos;
			xorigin = xpos;	
cout<<"Ant not alive. Ant created and spawned at: x="<<xorigin<<" z="<<zorigin<<endl;

			//xspeed = sin(0.4*(3,14/2))*antspeed;
			//zspeed = -cos(0.4*(3,14/2))*antspeed;
		}
	}	//endif antspawn

};	//end class

