#include "hud.h"

void DrawHUD()
{
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    glOrtho( -100.0f, 100.0f, -100.0f, 100.0f, -0.01f, 1.0f );
    glMatrixMode( GL_MODELVIEW );

    glPushMatrix(); 	//map
    glLoadIdentity();

//    glColor3f( 1.0f, 1.0f, 0.0f );
//    glBegin( GL_LINE_LOOP);
//    glVertex2f( -95.0f, 95.0f );
//    glVertex2f( -95.0f, 50.0f );
//    glVertex2f( -50.0f, 50.0f );
//    glVertex2f( -50.0f, 95.0f );
//    glEnd();

    //aim
    glColor3f( 0.0f, 1.0f, 0.0f );
    glBegin(GL_LINE_LOOP);
    glVertex2f( -4.0f, 0.1f );
    glVertex2f( -0.1f, 0.1f );
    glVertex2f( -0.1f, 4.0f );
    glVertex2f( 0.1f, 4.0f );
    glVertex2f( 0.1f, 0.1f );
    glVertex2f( 4.0f, 0.1f );
    glVertex2f( 4.0f, -0.1f );
    glVertex2f( 0.1f, -0.1f );
    glVertex2f( 0.1f, -4.0f );
    glVertex2f( -0.1f, -4.0f );
    glVertex2f( -0.1f, -0.1f );
    glVertex2f( -4.0f, -0.1f );
    glVertex2f( -4.0f, -0.1f );
    glEnd();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();

    glMatrixMode( GL_MODELVIEW );
    glPopMatrix();
}
