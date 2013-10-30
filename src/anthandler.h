
#include <GL/glew.h> // Include the GLEW header file  
#include <vector> 
#include <iostream>

using namespace std;

extern float camheight;
extern float xpos, zpos;
extern float yrot, xrot;
extern const int maxants;
extern class Ant antarray[100];


void AntHandler(string action)
{
	if(action == "move")	//move the existing Ants
	{	
		for(int antcounter = 0; antcounter<maxants; antcounter++)
		{
			if(antarray[antcounter].antalive == 1) 
			{
			antarray[antcounter].ki();

						//antarray[antcounter].antworldarray[x][z] = worldvector[antarray[antcounter].xAntPosition-1+x][antarray[antcounter].zAntPosition-1+z].blocktype;




			}
		}	
	}

	if(action == "spawn")	//create a new Ant
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

