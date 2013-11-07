#include "leveldrawer.h"

LevelDrawer::LevelDrawer()
{
    drawBlocks();
}

void LevelDrawer::drawBlocks()
{
    std::vector< std::vector<Square> >::iterator row;
    std::vector<Square>::iterator col;
    for (row = worldvector.begin(); row != worldvector.end(); row++)
        for (col = row->begin(); col != row->end(); col++)
        {
            if (col->block == 1 || col->block == 2 || col->antHill == 1 || col->food > 0)
            {
                glPushMatrix();
                glTranslated(row - worldvector.begin(), 0, col - row->begin());
                glScalef(0.5,0.5,0.5);

                if(col->antHill)
                {
                    glColor3f(0.7,0.6,0.6);
                    glBegin(GL_POLYGON);
                    glVertex3f(-1, 0.001, -1);
                    glVertex3f(1, 0.001, -1);
                    glVertex3f(1, 0.001, 1);
                    glVertex3f(-1, 0.001, 1);
                    glEnd();
                }

                if(col->block == 1)
                {
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
                }
                if(col->food > 0)
                {
                    float foodsize = (col->food)*0.005+0.5;
                    glColor3f(1,1,0);
                    glBegin(GL_POLYGON);
                    glVertex3f(-foodsize, 0.001, -foodsize);
                    glVertex3f(foodsize, 0.001, -foodsize);
                    glVertex3f(foodsize, 0.001, foodsize);
                    glVertex3f(-foodsize, 0.01, foodsize);
                    glEnd();
                }
                glPopMatrix();

            }//end if
        }// end for
}// end method
