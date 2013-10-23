
#include <GL/glew.h> // Include the GLEW header file  
#include <vector> 
#include <iostream>

using namespace std;

extern float xpos, zpos;
extern int maxblocks;
extern class Block blockarray[100];


void BlockHandler(string action)
{
	if(action == "draw")	//draw the existing Blocks
	{	
		for(int blockcounter = 0; blockcounter<maxblocks; blockcounter++)
		{
			if(blockarray[blockcounter].blockcreated == 1) 
			{
				blockarray[blockcounter].drawBlock();
			
			}
		}	
	}

	if(action == "spawn")	//create new Block
	{	
	
		for(int blockcounter=0; blockcounter<maxblocks; blockcounter++)
		{
			if(blockarray[blockcounter].blockcreated == 0)
			{
				blockarray[blockcounter].spawnBlock();
				blockcounter = maxblocks;
				
			}			
		}
		
	}
}

