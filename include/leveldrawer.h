#include "levelmanager.h"

extern LevelManager levelManager1;

class LevelDrawer        //class for all classes, Wall-Blocks and Food-Blocks
{

public:
        
	void drawBlocks()
	{
		for(int i = 0; i < levelManager1.blockVector().size(); i++)
		{
		
		}
		           /*  glPushMatrix();
		             glTranslated(blockVec.at(i).xBlockPosition, blockVec.at(i).xyBlockPosition, blockVec.at(i).zBlockPosition);                
		             glScalef(0.5,0.5,0.5);
		             
		             // Block
		             glBegin(GL_POLYGON);
		             if(blocktype == 1)
		                     glColor3f(0,0,1);
		             else
		                     glColor3f(1,1,0);
		             glVertex3f(-1, 1, -1);
		             glVertex3f(1, 1, -1);
		             glVertex3f(1, 1, 1);
		             glVertex3f(-1, 1, 1);
		             glEnd();
		             glPopMatrix();

		             }*/
	}
                
}; //end Class
