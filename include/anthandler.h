
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
		for(int antcounter = 0; antcounter<maxants; antcounter++)
		{
			if(antarray[antcounter].antalive == 1) 
			{
			antarray[antcounter].ki();
			
			}
		}	
	}

	if(action == "spawn")	//create new Bullet
	{	
		for(int antcounter=0; antcounter<maxants; antcounter++)
		{
			if(antarray[antcounter].antalive == 0)
			{
			antarray[antcounter].antspawn();
			cout<<"antcounter "<<antcounter<<endl;
			antcounter = maxants;
				
			}			
		}
		
	}
}

