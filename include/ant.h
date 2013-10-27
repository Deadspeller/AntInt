#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>

//extern  sf::RenderWindow DSWindow;

extern vector < vector <worldstruct> > worldvector;

extern float antspeed;
extern float xpos, ypos, zpos;
extern float colobjects[6][4];

extern float roundTime;

using namespace std;

void shootcollision();
void impactdraw(char);
	
class Ant
{
	public:
	vector <vector <int> > antworldvector;
	int antworldarray[3][3];
	bool xpluscollision, xminuscollision , zpluscollision , zminuscollision ;
	bool xplusfood , xminusfood , zplusfood , zminusfood ;
	bool collision;
	float difTime, gesTime;
	bool antalive;
	float yorigin, zorigin, xorigin; //where the ant started


	int xAntPosition, yAntPosition, zAntPosition; //Position of the Ant
	int oldxAntPosition, oldyAntPosition, oldzAntPosition; //Position of the Ant
	Timer AntTimer;
	


	void ki()
	{
		static int status = 1;	
		static int done ;

		nearcheck();
	/*
	switch(status)
		{
			case 1:
					if(!zpluscollision && done)
					{
						status = 3;
						
					}
					else if(xpluscollision && zpluscollision && done)
					{
						cout<<"lasdfien"<<endl;
						status = 4;
					}
					
					done = antmove(1);
					break;
			case 2:
					if(!zminuscollision && done)
					{
						status = 4;
						
					}
					else if(xminuscollision && zminuscollision && done)
					{
						status = 3;
					}
					done = antmove(2);
					break;
			case 3:
					if(!xminuscollision && done)
					{
						status = 2;
						
					}
					else if(zpluscollision && xminuscollision && done)
					{
						status = 1;
					}
					done = antmove(3);
					break;
			case 4:
					if(!xpluscollision && done)
					{
						status = 1;
						
					}
					else if(zminuscollision && xpluscollision && done)
					{
						status = 2;
					}
					done = antmove(4);
					break;
		}*/

if(done)
{
	cout<<"antarray"<<endl;
	for(int a = 0; a < 3; a++)
	{
		cout<<antworldarray[0][a]<<antworldarray[1][a]<<antworldarray[2][a]<<endl;	
	}
}

		switch(status)
		{
			case 1:
					if(xpluscollision)
					{
						cout<<"case xpluscoll"<<endl;
						status = 3;
						xpluscollision = false;
					}
					if(zplusfood)
					{
						status =3;
					}
					if(zminusfood)
					{
						status =4;
					}
					done = antmove(1);
					break;
			case 2:
					if(xminuscollision)
					{
						status = 4;
						xminuscollision = false;
					}
					if(zplusfood)
					{
						status =3;
					}
					if(zminusfood)
					{
						status =4;
					}
					done = antmove(2);
					break;
			case 3:
					if(zpluscollision)
					{
						status = 2;
						zpluscollision = false;
					}
					if(xplusfood)
					{
						status =1;
					}
					if(xminusfood)
					{
						status =2;
					}
					done = antmove(3);
					break;
			case 4:
					if(zminuscollision)
					{
						status = 1;
						zminuscollision = false;
					}
					if(xplusfood)
					{
						status =1;
					}
					if(xminusfood)
					{
						status =2;
					}
					done = antmove(4);
					break;
		}


	}


	
	int antmove(int a)	//move the ant
	{
		if(antalive)	//if the ant is alive
		{ 	

			if(gesTime >= roundTime)
			{

				oldxAntPosition = xAntPosition;
				oldzAntPosition = zAntPosition;
				switch(a)	//move
				{
					case 1:	//vor
							xAntPosition += 1;
							break;
					case 2:	//zurück
							xAntPosition -= 1;
							break;
					case 3:	//rechts
							zAntPosition += 1;
							break;
					case 4:	//links
							zAntPosition -= 1;
							break;
				}
				antcollision();	//check if collision

				if(collision)
				{
					cout<<"kollision"<<endl;
					xAntPosition = oldxAntPosition;
					zAntPosition = oldzAntPosition;
				}
				
				worldvector[oldxAntPosition][oldzAntPosition].blocktype = 0;
				worldvector[xAntPosition][zAntPosition].blocktype = 3;
				gesTime = 0;

				return 1;
			}

			//draw the ant
			glPushMatrix();
			glTranslated(xAntPosition, yAntPosition, zAntPosition);		

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

			  glScalef(0.5,0.5,0.5);
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
            glEnd();
            glPopMatrix();

			AntTimer.stop();
			difTime = AntTimer.getElapsedTimeInSec();
			if(difTime > 0.1) difTime = 0;	//remove first time
			gesTime += difTime;
			AntTimer.start();
		}
	return 0;
	} //endif antmove



	void antcollision()
	{
		collision = false;
		
		if(xAntPosition < 50 && zAntPosition < 50)
		if(xAntPosition > 0 && zAntPosition > 0)
		if(worldvector[xAntPosition][zAntPosition].blocktype == 1)
		{
			collision = true;
		}

	}//endif antcollision

void nearcheck()
{

	/*for(int a = 0; a < 3; a++)
	{
		for(int b = 0; b<3; b++)
		{
			antworldarray[a][b] = worldvector[xAntPosition-1+a][zAntPosition-1+a].blocktype;
		}
	}*/

	xpluscollision = false;
	xminuscollision = false;
	zpluscollision = false;
	zminuscollision = false;

	xplusfood = false;
	xminusfood = false;
	zplusfood = false;
	zminusfood = false;

	if(worldvector[xAntPosition+1][zAntPosition].blocktype == 1)
	{
		xpluscollision = true;
	}
	if(worldvector[xAntPosition-1][zAntPosition].blocktype == 1)
	{
		xminuscollision = true;
	}
	if(worldvector[xAntPosition][zAntPosition+1].blocktype == 1)
	{
		zpluscollision = true;
	}
	if(worldvector[xAntPosition][zAntPosition-1].blocktype == 1)
	{
		zminuscollision = true;
	}

	if(worldvector[xAntPosition+1][zAntPosition].blocktype == 2)
	{
		xplusfood = true;
	}
	if(worldvector[xAntPosition-1][zAntPosition].blocktype == 2)
	{
		xminusfood = true;
	}
	if(worldvector[xAntPosition][zAntPosition+1].blocktype == 2)
	{
		zplusfood = true;
	}
	if(worldvector[xAntPosition][zAntPosition-1].blocktype == 2)
	{
		zminusfood = true;
	}

}	//end nearcheck


	void antspawn()	//spawn a new ant
	{
		
		if(antalive == 0)	//if ant is not already alive
		{
			
			antalive = true;
			gesTime = 0;
			yorigin = 0.001;
		
				zAntPosition = round(zpos+1);
				xAntPosition = round(xpos+1);


	zorigin = zAntPosition;
	xorigin = xAntPosition;

worldvector[xAntPosition][zAntPosition].blocktype = 3;
cout<<"Zeiger pos: "<<xpos<<" "<<zpos<<endl;
cout<<"Ant not alive. Ant created and spawned at: x="<<xAntPosition<<" z="<<zAntPosition<<endl;

		}
	}	//endif antspawn

};	//end class

