
#include <GL/glew.h> // Include the GLEW header file  
#include <vector> 
#include <iostream>

using namespace std;

extern float camheight;
extern float bulletpos;
extern float xpos, zpos;
extern float yrot, xrot;
extern int maxants;
extern class Ant antarray[100];


void AntHandler(string action)
{
	if(action == "move")	//move the existing Bullets
	{	
		for(int movecounter = 0; movecounter<maxants; movecounter++)
		{
			if(antarray[movecounter].antalive == 1) 
			{
			antarray[movecounter].main();
			
			}
		}	
	}

	if(action == "handle")	//create new Bullet
	{	
	
		for(int handlecounter=0; handlecounter<maxants; handlecounter++)
		{
			if(antarray[handlecounter].antalive == 0)
			{
			antarray[handlecounter].antspawn();
			handlecounter = maxants;
			}			
		}

			
	}
}

