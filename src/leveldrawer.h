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
//        levelManager1.update(); // nur test! sollte eigtl dort aufgerufen werden wo dem worldvec ein neuer block hinzugefügt wird!

        std::vector< std::vector<Square> >::iterator row;
        std::vector<Square>::iterator col;
        for(row = worldvector.begin(); row != worldvector.end(); row++)
            for(col = row->begin(); col != row->end(); col++)
            {
                if(col->blockType == 1 || col->blockType == 2)
                {
                    glPushMatrix();
                    glTranslated(row - worldvector.begin(), 0, col - row->begin());
                    glScalef(0.5,0.5,0.5);

                    switch(col->blockType)
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

                        default:
                                break;

                    }
                    glPopMatrix();

                }//end if
            }// end for
    }// end method
                
}; //end Class
