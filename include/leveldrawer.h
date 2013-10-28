#include "levelmanager.h"

extern LevelManager levelManager1;

class LevelDrawer        //class for all classes, Wall-Blocks and Food-Blocks
{

public:
        
    LevelDrawer()
    {
        drawBlocks();
    }

	void drawBlocks()
	{
        levelManager1.update(); // nur test! sollte eigtl dort aufgerufen werden wo dem worldvec ein neuer block hinzugefügt wird!

        std::vector<Block*>::iterator it;
        std::vector<Block*> BlockVec = levelManager1.blockVector();
        for(it = BlockVec.begin(); it != BlockVec.end(); it++ )
        {

            if((*it)->blockType != 0)
            {
                     glPushMatrix();
                     glTranslated((*it)->xBlockPosition, (*it)->yBlockPosition, (*it)->zBlockPosition);
                     glScalef(0.5,0.5,0.5);
		             
                     // Block
                     glBegin(GL_POLYGON);

                     if((*it)->blockType == 1)
                             glColor3f(0,0,1);
                     else
                             glColor3f(1,1,0);
                     glVertex3f(-1, 1, -1);
                     glVertex3f(1, 1, -1);
                     glVertex3f(1, 1, 1);
                     glVertex3f(-1, 1, 1);
                     glEnd();
                     glPopMatrix();

                     }
        }
	}
                
}; //end Class
