#include "leveldrawer.h"
#define BLOCK_HEIGHT 0.3
LevelDrawer::LevelDrawer()
{
    drawBlocks();
}

sf::SoundBuffer blockSoundBuffer;
sf::Sound blockSound;
void LevelDrawer::drawBlocks()
{

    static float difTime = 0;
    std::vector< std::vector<Square> >::iterator row;
    std::vector<Square>::iterator col;

    for (row = worldvector.begin(); row != worldvector.end(); row++)
        for (col = row->begin(); col != row->end(); col++)
        {
            if (col->block == 1 || col->block == 2 || col->antHill == 1 || col->food > 0)
            {

                BlockTimer.stop();
                difTime = BlockTimer.getElapsedTimeInSec();
                //if(difTime > 2) difTime = 0;	//remove first time
                if(col->yBlockAnim > 0.5)
                {
                    col->yBlockSpeed += 50*difTime;
                    col->yBlockAnim -= col->yBlockSpeed * difTime;
                }
                else
                if(col->yBlockAnim < 0.5)
                {
                    cout<<"sound"<<endl;
//                    sf::SoundBuffer blockSoundBuffer;
//                    blockSoundBuffer.loadFromFile("sounds/blocksound.wav");
//                    sf::Sound blockSound;
//                    blockSound.setBuffer(blockSoundBuffer);
                    blockSoundBuffer.loadFromFile("sounds/blocksound.wav");
                    blockSound.setBuffer(blockSoundBuffer);
                    blockSound.setVolume(100);
                    blockSound.play();
                    blockSound.getStatus();

                    col->yBlockAnim = 0.5;
                }


                glPushMatrix();
                if(col->block == 1)
                glTranslated(row - worldvector.begin(), col->yBlockAnim, col - row->begin());
                else
                glTranslated(row - worldvector.begin(), 0, col - row->begin());

                glScalef(0.5,0.5,0.5);

                if(col->antHill)
                {
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D, tex_hill);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glColor3f(1,1,1);

                    glBegin(GL_POLYGON);
                    glTexCoord2d(0,0);
                    glVertex3f(-1, 0.001, -1);
                    glTexCoord2d(1,0);
                    glVertex3f(1, 0.001, -1);
                    glTexCoord2d(1,1);
                    glVertex3f(1, 0.001, 1);
                    glTexCoord2d(0,1);
                    glVertex3f(-1, 0.001, 1);
                    glEnd();
                }

                if(col->block == 1)
                {

                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glColor3f(1,1,1); // If you do not set a color, the textured area will appear black.

                    glBegin(GL_POLYGON); //top
                    glTexCoord2d(0,0);
                    glVertex3f(-1, BLOCK_HEIGHT, -1);

                    glTexCoord2d(1,0);
                    glVertex3f(1, BLOCK_HEIGHT, -1);

                    glTexCoord2d(1,1);
                    glVertex3f(1, BLOCK_HEIGHT, 1);

                    glTexCoord2d(0,1);
                    glVertex3f(-1, BLOCK_HEIGHT, 1);
                    glEnd();

                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glColor3f(1,1,1);
                    glBegin(GL_POLYGON); //side
                    glTexCoord2d(0,0);  glVertex3f(-1, BLOCK_HEIGHT, 1);
                    glTexCoord2d(1,0);  glVertex3f(-1, BLOCK_HEIGHT, -1);
                    glTexCoord2d(1,1);  glVertex3f(-1, -1, -1);
                    glTexCoord2d(0,1);  glVertex3f(-1, -1, 1);
                    glEnd();

                    glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glColor3f(1,1,1);
                    glBegin(GL_POLYGON); //side
                    glTexCoord2d(0,0);  glVertex3f(1, BLOCK_HEIGHT, 1);
                    glTexCoord2d(1,0);  glVertex3f(-1, BLOCK_HEIGHT, 1);
                    glTexCoord2d(1,1);  glVertex3f(-1, -1, 1);
                    glTexCoord2d(0,1);  glVertex3f(1, -1, 1);
                    glEnd();

                    glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glColor3f(1,1,1);
                    glBegin(GL_POLYGON); //side
                    glTexCoord2d(0,0);  glVertex3f(1, BLOCK_HEIGHT, -1);
                    glTexCoord2d(1,0);  glVertex3f(-1, BLOCK_HEIGHT, -1);
                    glTexCoord2d(1,1);  glVertex3f(-1, -1, -1);
                    glTexCoord2d(0,1);  glVertex3f(1, -1, -1);
                    glEnd();

                    glBindTexture(GL_TEXTURE_2D, tex_wood_horizontal);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glColor3f(1,1,1);
                    glBegin(GL_POLYGON); //side
                    glTexCoord2d(0,0);  glVertex3f(1, BLOCK_HEIGHT, 1);
                    glTexCoord2d(1,0);  glVertex3f(1, BLOCK_HEIGHT, -1);
                    glTexCoord2d(1,1);  glVertex3f(1, -1, -1);
                    glTexCoord2d(0,1);  glVertex3f(1, -1, 1);
                    glEnd();
                    glDisable(GL_TEXTURE_2D);
                }
                if(col->food > 0)
                {
                    glEnable(GL_TEXTURE_2D);
                    glEnable(GL_BLEND);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                    if(col->food > 90)
                    {
                        glBindTexture(GL_TEXTURE_2D, tex_honeycomb100);
                    }
                    else if(col->food >= 80)
                    {
                         glBindTexture(GL_TEXTURE_2D, tex_honeycomb80);
                    }
                    else if(col->food >= 60)
                    {
                         glBindTexture(GL_TEXTURE_2D, tex_honeycomb60);
                    }
                    else if(col->food >= 50)
                    {
                         glBindTexture(GL_TEXTURE_2D, tex_honeycomb50);
                    }
                    else if(col->food >= 30)
                    {
                         glBindTexture(GL_TEXTURE_2D, tex_honeycomb30);
                    }
                    else if(col->food >= 20)
                    {
                         glBindTexture(GL_TEXTURE_2D, tex_honeycomb10);
                    }
                    else if(col->food > 0)
                    {
                         glBindTexture(GL_TEXTURE_2D, tex_honeycomb5);
                    }



//                    glEnable(GL_TEXTURE_2D);
//                    glEnable(GL_BLEND);
//                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//                    glBindTexture(GL_TEXTURE_2D, tex_honeycomb);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glColor4f(1,1,1,1);

                    glBegin(GL_POLYGON);
                    glTexCoord2d(0,0);
                    glVertex3f(-1, 0.001, -1);
                    glTexCoord2d(1,0);
                    glVertex3f(1, 0.001, -1);
                    glTexCoord2d(1,1);
                    glVertex3f(1, 0.001, 1);
                    glTexCoord2d(0,1);
                    glVertex3f(-1, 0.001, 1);
                    glEnd();
                }
                glPopMatrix();

            }//end if
        }// end for
    BlockTimer.start();

    for (size_t i = 0; i < antHill1.antVec.size(); i++)
    {
        glPushMatrix();
        glTranslated(antHill1.antVec[i].xAntAnimPosition, antHill1.antVec[i].yAntPosition, antHill1.antVec[i].zAntAnimPosition);

        switch (antHill1.antVec[i].movedirection)
        {
            case 0:	//vor
                    glRotatef(0,0.0,1.0,0.0);
                    break;
            case 1:	//rechts
                    glRotatef(-90,0.0,1.0,0.0);
                    break;
            case 2:	//zurück
                    glRotatef(180,0.0,1.0,0.0);
                    break;
            case 3:	//links
                    glRotatef(90,0.0,1.0,0.0);
                    break;
        }

        glScalef(0.5,0.5,0.5);


            glEnable(GL_TEXTURE_2D);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glBindTexture(GL_TEXTURE_2D, tex_antbody);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glColor4f(1,1,1,1); // If you do not set a color, the textured area will appear black.
            glColor3f(1,1,1);
            if(antHill1.antVec[i].antwarning==1) glColor3f(0.3,0.3,0.3);
            else glColor3f(1,1,1);
        blockTextDraw(0.55, 0.8, 0.01, 0.3, -0.25, 0.25);
            glDisable(GL_BLEND);
            glDisable(GL_TEXTURE_2D);
            glEnd();

            glEnable(GL_TEXTURE_2D);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glBindTexture(GL_TEXTURE_2D, tex_antbody);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glColor4f(1,1,1,1); // If you do not set a color, the textured area will appear black.
            //glColor3f(1,1,1);
            if(antHill1.antVec[i].antwarning) glColor3f(0.3,0.3,0.3);
            else glColor3f(1,1,1);
        blockTextDraw(0.1, 0.5, 0.01, 0.25, -0.15, 0.15);
            glDisable(GL_BLEND);
            glDisable(GL_TEXTURE_2D);
            glEnd();

            glEnable(GL_TEXTURE_2D);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glBindTexture(GL_TEXTURE_2D, tex_antback);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glColor4f(1,1,1,1); // If you do not set a color, the textured area will appear black.
            glColor3f(1,1,1);
            if(antHill1.antVec[i].antwarning) glColor3f(0.3,0.3,0.3);
            else glColor3f(1,1,1);
        blockTextDraw(0, -1, 0.01, 0.3, -0.3, 0.3);
            glDisable(GL_BLEND);
            glDisable(GL_TEXTURE_2D);
            glEnd();

        glColor3f(1,0.1,0.1);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, tex_antfeet);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glColor4f(1,1,1,1); // If you do not set a color, the textured area will appear black.
        if(antHill1.antVec[i].antwarning) glColor4f(1,0.3,0.3,0.3);
        else glColor4f(1,1,1,1);
        glBegin(GL_POLYGON); //ground
        glTexCoord2d(1,0);  glVertex3f(-1, 0.01, -1);
        glTexCoord2d(1,1);  glVertex3f(1, 0.01, -1);
        glTexCoord2d(0,1);  glVertex3f(1, 0.01, 1);
        glTexCoord2d(0,0);  glVertex3f(-1, 0.01, 1);
        glEnd();
        glDisable(GL_BLEND);
        glDisable(GL_TEXTURE_2D);
        glEnd();
        glPopMatrix();
    }


}// end method


void blockDraw(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax)
{
    glColor3f(1,0.2,0.2);   //bottom
    glBegin(GL_POLYGON);
    glVertex3f(xmin, ymin, zmin);
    glVertex3f(xmax, ymin, zmin);
    glVertex3f(xmax, ymin, zmax);
    glVertex3f(xmin, ymin, zmax);
    glEnd();

    glColor3f(1,0.2,0.2);   //front
    glBegin(GL_POLYGON);
    glVertex3f(xmax, ymin, zmin);
    glVertex3f(xmax, ymax, zmin);
    glVertex3f(xmax, ymax, zmax);
    glVertex3f(xmax, ymin, zmax);
    glEnd();

    glColor3f(1,0.2,0.2);   //back
    glBegin(GL_POLYGON);
    glVertex3f(xmin, ymin, zmin);
    glVertex3f(xmin, ymax, zmin);
    glVertex3f(xmin, ymax, zmax);
    glVertex3f(xmin, ymin, zmax);
    glEnd();

    glColor3f(1,0.2,0.2);   //left
    glBegin(GL_POLYGON);
    glVertex3f(xmin, ymin, zmin);
    glVertex3f(xmin, ymax, zmin);
    glVertex3f(xmax, ymax, zmin);
    glVertex3f(xmax, ymin, zmin);
    glEnd();

    glColor3f(1,0.2,0.2);   //right
    glBegin(GL_POLYGON);
    glVertex3f(xmin, ymin, zmax);
    glVertex3f(xmin, ymax, zmax);
    glVertex3f(xmax, ymax, zmax);
    glVertex3f(xmax, ymin, zmax);
    glEnd();

    glColor3f(1,0.2,0.2);   //top
    glBegin(GL_POLYGON);
    glVertex3f(xmin, ymax, zmin);
    glVertex3f(xmax, ymax, zmin);
    glVertex3f(xmax, ymax, zmax);
    glVertex3f(xmin, ymax, zmax);
    glEnd();

}

void blockTextDraw(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax)
{
       //bottom
    glBegin(GL_POLYGON);
    glTexCoord2d(0,0);
    glVertex3f(xmin, ymin, zmin);
    glTexCoord2d(1,0);
    glVertex3f(xmax, ymin, zmin);
    glTexCoord2d(1,1);
    glVertex3f(xmax, ymin, zmax);
    glTexCoord2d(0,1);
    glVertex3f(xmin, ymin, zmax);
    glEnd();

//front
    glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
    glVertex3f(xmax, ymin, zmin);
        glTexCoord2d(1,0);
    glVertex3f(xmax, ymax, zmin);
        glTexCoord2d(1,1);
    glVertex3f(xmax, ymax, zmax);
        glTexCoord2d(0,1);
    glVertex3f(xmax, ymin, zmax);
    glEnd();

//back
    glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
    glVertex3f(xmin, ymin, zmin);
        glTexCoord2d(1,0);
    glVertex3f(xmin, ymax, zmin);
        glTexCoord2d(1,1);
    glVertex3f(xmin, ymax, zmax);
        glTexCoord2d(0,1);
    glVertex3f(xmin, ymin, zmax);
    glEnd();

//left
    glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
    glVertex3f(xmin, ymin, zmin);
        glTexCoord2d(1,0);
    glVertex3f(xmin, ymax, zmin);
        glTexCoord2d(1,1);
    glVertex3f(xmax, ymax, zmin);
        glTexCoord2d(0,1);
    glVertex3f(xmax, ymin, zmin);
    glEnd();

//right
    glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
    glVertex3f(xmin, ymin, zmax);
        glTexCoord2d(1,0);
    glVertex3f(xmin, ymax, zmax);
        glTexCoord2d(1,1);
    glVertex3f(xmax, ymax, zmax);
        glTexCoord2d(0,1);
    glVertex3f(xmax, ymin, zmax);
    glEnd();

//top
    glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
    glVertex3f(xmin, ymax, zmin);
        glTexCoord2d(1,0);
    glVertex3f(xmax, ymax, zmin);
        glTexCoord2d(1,1);
    glVertex3f(xmax, ymax, zmax);
        glTexCoord2d(0,1);
    glVertex3f(xmin, ymax, zmax);
    glEnd();


}
