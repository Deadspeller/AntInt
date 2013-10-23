#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <time.h>

//extern  sf::RenderWindow DSWindow;

extern vector <blockstruct> blockvector;

extern float antspeed;
extern float xpos, ypos, zpos;
extern float colobjects[6][4];

using namespace std;

void shootcollision();
void impactdraw(char);

class Ant
{
	public:
	bool collision = false;
	float difTime, gesTime;
	float xspeed, zspeed, yspeed;
	float xdif, zdif, ydif;
	float xdimension =3, zdimension =2;
	bool antalive;
	float yorigin, zorigin, xorigin;
	int i = 0;
	Timer AntTimer;
	int status = 1;	

int backwards = false;

	void main()
	{
		/*if(!xcollision && !backwards) 
		{
			antmove(4);		
		}
		if(xcollision || backwards)
		{
			antmove(3);
			if(backwards) backwards = 0;
			else backwards = 1;
		}*/
	
		switch(status)
		{
			case 1:
					antmove(1);
					if(collision)
					{
						status = 3;
						collision = false;
					}
					break;
			case 2:
					antmove(2);
					if(collision)
					{
						status = 4;
						collision = false;
					}
					break;
			case 3:
					antmove(3);
					if(collision)
					{
						status = 2;
collision = false;
					}
					break;
			case 4:
					antmove(4);
					if(collision)
					{
						status = 1;
collision = false;
					}
					break;
		}
	}


	
	void antmove(int a)	//move the ant
	{
		if(antalive)	//if the ant is alive
		{ 	
			
			if(gesTime >= 1)
			{
			switch(a)	//move
			{
				case 1:	//vor
						xdif += 2;
						break;
				case 2:	//zurück
						xdif -= 2;
						break;
				case 3:	//rechts
						zdif += 2;
						break;
				case 4:	//links
						zdif -= 2;
						break;
			}
			antcollision();	//check if collision
			if(collision)	//if collision go back
			{
				cout<<"kollision"<<endl;
				switch(a)	//move
				{
					case 1:	//vor
							xdif -= 2;
							break;
					case 2:	//zurück
							xdif += 2;
							break;
					case 3:	//rechts
							zdif -= 2;
							break;
					case 4:	//links
							zdif += 2;
							break;
				}
			}
			gesTime = 0;
			}

			//draw the ant
			glPushMatrix();
			glTranslated(xorigin+xdif, yorigin+ydif, zorigin+zdif);		

			switch(a)
			{
				case 1:	//vor
						glRotatef(0,0.0,1.0,0.0);
						break;
				case 2:	//zurück
						glRotatef(180,0.0,1.0,0.0);
						break;
				case 3:	//rechts
						glRotatef(-90,0.0,1.0,0.0);
						break;
				case 4:	//links
						glRotatef(90,0.0,1.0,0.0);
						break;
			}	

			glScalef(1,1,1);
			glColor3f(1,0.1,0.1);
		 
glEnable(GL_TEXTURE_2D);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    	glBindTexture(GL_TEXTURE_2D, tex_ant);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    	glColor4f(1,1,1,1); // If you do not set a color, the textured area will appear black.

    	glBegin(GL_POLYGON); //ground
    	glTexCoord2d(1,0);  glVertex3f(-1, 1, -1);
    	glTexCoord2d(1,1);  glVertex3f(1, 1, -1);
    	glTexCoord2d(0,1);  glVertex3f(1, 1, 1);
    	glTexCoord2d(0,0);  glVertex3f(-1, 1, 1);
    	glEnd();
glDisable(GL_BLEND);
    	glDisable(GL_TEXTURE_2D);


			// Body
			/*glBegin(GL_POLYGON);
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
			glEnd();*/

			glEnd();
			glPopMatrix();



				AntTimer.stop();
				difTime = AntTimer.getElapsedTimeInSec();
				if(difTime > 0.1) difTime = 0;	//remove first time
				gesTime += difTime;
				AntTimer.start();
		}
	} //endif antmove



	void antcollision()
	{
		collision = false;
		/*xcollision = false;
		zcollision = false; */
cout<<"blocks seen by ant: "<<blockvector.size()<<endl;
if(blockvector.size()>0)
for(int i=0; i<blockvector.size(); i++)
		{
			if(xorigin+xdif > blockvector[i].minx && xorigin+xdif < blockvector[i].maxx)
			{
				if(zorigin+zdif > blockvector[i].minz && zorigin+zdif < blockvector[i].maxz)
				{
cout<<"struct collision"<<endl;
collision = true;
	
				}
			}
		}

/*
cout<<"normale collision"<<endl;
		for(int i=0; i<6; i++)
		{
			if(xorigin+xdif > colobjects[i][0] && xorigin+xdif < colobjects[i][1])
			{
				if(zorigin+zdif > colobjects[i][2] && zorigin+zdif < colobjects[i][3])
				{
//cout<<"kollision von"<<xorigin+xdif<<" und "<<colobjects[i][0] <<endl;
collision = true;

/*float xlinks, xrechts, zunten, zoben;
xlinks = abs(colobjects[i][0] - (xorigin+xdif+1.2));
xrechts = abs(xorigin+xdif+1.2 - (colobjects[i][1]));

zunten = abs(colobjects[i][2] - (zorigin+zdif+1.2));
zoben = abs(zorigin+zdif+1.2 - (colobjects[i][3]));


if(zunten <0.5 || zoben <0.5)
{
	zcollision = true;
}
	
if(xlinks <0.5 || xrechts <0.5)
{
	xcollision = true;
}*/
	/*				
				}
			}
		}
		*/
	
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
			yorigin = 0.001;
		
			if(fmod(zpos,2) > 1)	
				zorigin = ceil(zpos+1)+1;
			else if(fmod(zpos,2) > 0)	
				zorigin = floor(zpos+1)+1;
			
			if(fmod(xpos,2) > 1)	
				xorigin = ceil(xpos+1)+1;
			else if(fmod(xpos,2) > 0)	
				xorigin = floor(xpos+1)+1;

	
cout<<"Zeiger pos: "<<xpos<<" "<<zpos<<endl;
cout<<"Ant not alive. Ant created and spawned at: x="<<xorigin<<" z="<<zorigin<<endl;

			//xspeed = sin(0.4*(3,14/2))*antspeed;
			//zspeed = -cos(0.4*(3,14/2))*antspeed;
		}
	}	//endif antspawn

};	//end class

