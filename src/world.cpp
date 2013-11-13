#include "world.h"

void world()	//Draw the world
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex_grass);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glColor3f(1,1,1); // If you do not set a color, the textured area will appear black.

    glBegin(GL_POLYGON); //ground
    glTexCoord2d(0,0);
    glVertex3f(0.5, 0, 0.5);

    glTexCoord2d(zworldsize-2,0);
    glVertex3f(0.5, 0, zworldsize-1.5);

    glTexCoord2d(zworldsize-2,xworldsize-2);
    glVertex3f(xworldsize-1.5, 0, zworldsize-1.5);

    glTexCoord2d(0,xworldsize-2);
    glVertex3f(xworldsize-1.5, 0, 0.5);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
