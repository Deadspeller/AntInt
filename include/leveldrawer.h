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

            if((*it)->blockType == 1 || (*it)->blockType == 2 || (*it)->blockType == 4)
            {
            	glPushMatrix();
				glTranslated((*it)->xBlockPosition, (*it)->yBlockPosition, (*it)->zBlockPosition);
                glScalef(0.5,0.5,0.5);
		             
				switch((*it)->blockType)
				{
					case 1: 	//Block
							glColor3f(0.8,0.8,0.8);
							glBegin(GL_POLYGON);
							glVertex3f(-1, 1, -1);
                 			glVertex3f(1, 1, -1);
					        glVertex3f(1, 1, 1);
					        glVertex3f(-1, 1, 1);
					        glEnd();

							glEnable(GL_TEXTURE_2D);
							glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
							glColor3f(1,1,1);
							glBegin(GL_POLYGON); //ground
							glTexCoord2d(0,0);  glVertex3f(-1, 1, 1);
							glTexCoord2d(1,0);  glVertex3f(-1, 1, -1);
							glTexCoord2d(1,1);  glVertex3f(-1, -1, -1);
							glTexCoord2d(0,1);  glVertex3f(-1, -1, 1);
							glEnd();
	
							glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
							glColor3f(1,1,1);
							glBegin(GL_POLYGON); //ground
							glTexCoord2d(0,0);  glVertex3f(1, 1, 1);
							glTexCoord2d(1,0);  glVertex3f(-1, 1, 1);
							glTexCoord2d(1,1);  glVertex3f(-1, -1, 1);
							glTexCoord2d(0,1);  glVertex3f(1, -1, 1);
							glEnd();

							glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
							glColor3f(1,1,1);
							glBegin(GL_POLYGON); //ground
							glTexCoord2d(0,0);  glVertex3f(1, 1, -1);
							glTexCoord2d(1,0);  glVertex3f(-1, 1, -1);
							glTexCoord2d(1,1);  glVertex3f(-1, -1, -1);
							glTexCoord2d(0,1);  glVertex3f(1, -1, -1);
							glEnd();

							glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
							glColor3f(1,1,1);
							glBegin(GL_POLYGON); //ground
							glTexCoord2d(0,0);  glVertex3f(1, 1, 1);
							glTexCoord2d(1,0);  glVertex3f(1, 1, -1);
							glTexCoord2d(1,1);  glVertex3f(1, -1, -1);
							glTexCoord2d(0,1);  glVertex3f(1, -1, 1);
							glEnd();
							glDisable(GL_TEXTURE_2D);

                
							break;
					case 2: 	//Food
							glColor3f(1,1,0);
							glBegin(GL_POLYGON);
							glVertex3f(-1, 1, -1);
                 			glVertex3f(1, 1, -1);
					        glVertex3f(1, 1, 1);
					        glVertex3f(-1, 1, 1);
					        glEnd();
							break;
					case 4: 	//AntHill
							glColor3f(0.4,0.4,0.4);
							glBegin(GL_POLYGON);
							glVertex3f(-1, 1, -1);
                 		glVertex3f(1, 1, -1);
					      glVertex3f(1, 1, 1);
					      glVertex3f(-1, 1, 1);
					      glEnd();
							break;

					default:
							break;

				}
				glPopMatrix();

					

        }
        }
	}
                
}; //end Class
