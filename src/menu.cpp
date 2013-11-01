#include "menu.h"

bool menukeyStates[256]; // Keybuffer for multiple key-input
int menuplay = 0, continueplay=0;
int drawoptions = 0;
float selecty[4][2]={{55,35}, {25,5}, {-5,-25},{-35,-55}};
int menusel = 0;
void menukeyPressed (unsigned char key, int x, int y);
void menukeyUp (unsigned char key, int x, int y);
void menukeyOperations (void);
extern float hp;

void DrawMainMenu();
void DrawCredits();
Timer keytimer;
Timer waittimer;
float geskeyTime=0;
float geswaitTime=0;



void DrawMenu()
{
    menukeyOperations();

    switch (drawoptions)
    {
        case 0: DrawMainMenu(); break;
        case 1: ; break;
        case 2: DrawCredits(); break;
        case 3: ; break;
        case 4: ; break;
    }

}

void DrawMainMenu()
{
int a =0;
char menuTitel[30] = "Game made by Deadspeller";
char menu1s[30] = "Start Game";
char menu1c[30] = "Resume Game";
char menu1[30] = "Start Game";
char menu2[30] = "Options";
char menu3[30] = "Credits";
char menu4[30] = "Exit";


glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear color buffer and depth buffer
        glLoadIdentity();  // Load the Identity Matrix to reset our drawing locations

   glMatrixMode( GL_PROJECTION );
   glPushMatrix();
   glLoadIdentity();
   glOrtho( -100.0f, 100.0f, -100.0f, 100.0f, -0.01f, 1.0f );
   glMatrixMode( GL_MODELVIEW );

        glPushMatrix(); 	//Frame
        glLoadIdentity();
                glColor3f( 1.0f, 1.0f, 1.0f );
                glBegin( GL_LINE_LOOP);
                glVertex2f( -95.0f, 95.0f );
                glVertex2f( 95.0f, 95.0f );
                glVertex2f( 95.0f, -95.0f );
                glVertex2f( -95.0f, -95.0f );
            glEnd();

/*glPushMatrix(); 	//Title
        glLoadIdentity();
        glColor3f( 1.0f, 1.0f, 1.0f );
        glTranslatef( -90.0f, 80.0f, 0.0f );
                glScalef( 0.1f, 0.1f, 0.1f);
        a=0;
                while ( menuTitel[a] != '\0' )
            {
                glutStrokeCharacter( GLUT_STROKE_ROMAN, menuTitel[a]);
        a++;
        }

        glPushMatrix(); 	//Menu1
        glLoadIdentity();
        glColor3f( 1.0f, 1.0f, 1.0f );
        if (continueplay)
        {
            strcpy (menu1,menu1c);
            glTranslatef(-45,40,0);
        }
        else glTranslatef( -35.0f, 40.0f, 0.0f );
                glScalef( 0.1f, 0.1f, 0.1f);
        a=0;

                while ( menu1[a] != '\0' )
                {
                    glutStrokeCharacter( GLUT_STROKE_ROMAN, menu1[a]);
            a++;
        }


        glPushMatrix(); 	//Menu2
        glLoadIdentity();
        glColor3f( 1.0f, 1.0f, 1.0f );
        glTranslatef( -20.0f, 10.0f, 0.0f );
                glScalef( 0.1f, 0.1f, 0.1f);
        a=0;
                while ( menu2[a] != '\0' )
            {
                glutStrokeCharacter( GLUT_STROKE_ROMAN, menu2[a]);
        a++;
        }

        glPushMatrix(); 	//Menu3
        glLoadIdentity();
        glColor3f( 1.0f, 1.0f, 1.0f );
        glTranslatef( -20.0f, -20.0f, 0.0f );
                glScalef( 0.1f, 0.1f, 0.1f);
        a=0;
                while ( menu3[a] != '\0' )
            {
                glutStrokeCharacter( GLUT_STROKE_ROMAN, menu3[a]);
        a++;
        }

        glPushMatrix(); 	//Menu4
        glLoadIdentity();
        glColor3f( 1.0f, 1.0f, 1.0f );
        glTranslatef( -10.0f, -50.0f, 0.0f );
                glScalef( 0.1f, 0.1f, 0.1f);
        a=0;
                while ( menu4[a] != '\0' )
            {
                glutStrokeCharacter( GLUT_STROKE_ROMAN, menu4[a]);
        a++;
        }

        glPushMatrix(); 	//Select Frame
        glLoadIdentity();
        glBegin( GL_LINE_LOOP);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f( -50.1f, selecty[menusel] [0] +0.1);
                glVertex2f( 50.1f, selecty[menusel] [0] +0.1);
                glVertex2f( 50.1f, selecty[menusel] [1] +0.1);
                glVertex2f( -50.1f, selecty[menusel] [1] +0.1);
            glEnd();
*/
        glPushMatrix(); 	//Select
        glLoadIdentity();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glColor4f( 1.0f, 1.0f, 1.0f,0.1f );
                glBegin( GL_QUADS);
                glVertex2f( -50.0f, selecty[menusel] [0]);
                glVertex2f( 50.0f, selecty[menusel] [0]);
                glVertex2f( 50.0f, selecty[menusel] [1]);
                glVertex2f( -50.0f, selecty[menusel] [1]);
        glEnd();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();

  glMatrixMode( GL_MODELVIEW );
  glPopMatrix();

}

void DrawCredits()
{
int a=0;
char credits1[20] = "Code by Deadspeller";
char credits2[30] = "Textures from Internet";

glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear color buffer and depth buffer
        glLoadIdentity();  // Load the Identity Matrix to reset our drawing locations

   glMatrixMode( GL_PROJECTION );
   glPushMatrix();
   glLoadIdentity();
   glOrtho( -100.0f, 100.0f, -100.0f, 100.0f, -0.01f, 1.0f );
   glMatrixMode( GL_MODELVIEW );

        glPushMatrix(); 	//Frame
        glLoadIdentity();
                glColor3f( 1.0f, 1.0f, 1.0f );
                glBegin( GL_LINE_LOOP);
                glVertex2f( -95.0f, 95.0f );
                glVertex2f( 95.0f, 95.0f );
                glVertex2f( 95.0f, -95.0f );
                glVertex2f( -95.0f, -95.0f );
            glEnd();

/*
        glPushMatrix(); 	//Credits
        glLoadIdentity();
        glColor3f( 1.0f, 1.0f, 1.0f );
        glTranslatef( -60.0f, 20.0f, 0.0f );
                glScalef( 0.1f, 0.1f, 0.1f);
        a=0;
                while ( credits1[a] != '\0' )
                {
                    glutStrokeCharacter( GLUT_STROKE_ROMAN, credits1[a]);
                    a++;
                }

        glPushMatrix(); 	//Credits
        glLoadIdentity();
        glColor3f( 1.0f, 1.0f, 1.0f );
        glTranslatef( -70.0f, -20.0f, 0.0f );
                glScalef( 0.1f, 0.1f, 0.1f);
        a=0;
            while ( credits2[a] != '\0' )
                {
                    glutStrokeCharacter( GLUT_STROKE_ROMAN, credits2[a]);
                    a++;
                }
*/
    glMatrixMode( GL_PROJECTION );
    glPopMatrix();

  glMatrixMode( GL_MODELVIEW );
  glPopMatrix();

}

void menukeyPressed (unsigned char key, int x, int y) {
    menukeyStates[key] = true; // Set the state of the current key to pressed

}

void menukeyUp (unsigned char key, int x, int y) {
    menukeyStates[key] = false; // Set the state of the current key to not pressed
}

void menukeyOperations (void) {    //keyboard input

    if (menukeyStates['w']) {
    if (drawoptions==0)
    {
        if (menusel == 0) menusel = 3;
        else if (menusel == 1) menusel = 0;
        else if (menusel == 2) menusel = 1;
        else if (menusel == 3) menusel = 2;
    usleep(200000);
    }
    }

        if (menukeyStates['s']) {
    if (drawoptions==0)
    {
        if (menusel == 3) menusel = 0;
        else if (menusel == 0) menusel = 1;
        else if (menusel == 1) menusel = 2;
        else if (menusel == 2) menusel = 3;

        usleep(200000);
    }
    }

        if (menukeyStates['d']) {
        }

        if (menukeyStates['a']) {
        }

        if (menukeyStates['e']) {

            menukeyStates['e'] = false;
            if (menusel == 0)
            {
                menuplay=1;
                continueplay = 1;
            }
//            if (menusel == 3) exit(0);
            if (menusel == 2) drawoptions=2;
    }


        if (menukeyStates[27]) {
            drawoptions = 0;
        }
}
