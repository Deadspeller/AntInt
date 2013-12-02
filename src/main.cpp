#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <list>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <GL/glew.h>

#include "ant.h"
#include "anthill.h"
#include "inputmanager.h"
#include "hud.h"
#include "leveldrawer.h"
#include "levelmanager.h"
#include "menu.h"
#include "objectcreator.h"
#include "square.h"
#include "texture.h"
#include "timer.h"
#include "world.h"

using namespace std;

extern int mouseScrollValue;

// Game Configurations
int leftClickAction = 2;
float roundTime = 0.5;
bool gameStart = false;
size_t maxAnts = 50;
float AntSpeed = 0.5;
float lifeTime =1000;
//world
size_t xworldsize = 31;
size_t zworldsize = 31;

vector <vector <Square> > worldvector(xworldsize+1, vector<Square>(zworldsize+1)); //contains all informations about blocks, ants and food

//Classes
ObjectCreator objectCreator1;
LevelDrawer levelDrawer1;
LevelManager levelManager1;
AntHill antHill1(15, 15);


//AntHill antHill1;
float gesTime;
float difTime;

Timer maintimer;

//--OpenGL Variables--

//int xres = 640, yres = 480;	//size of the Window
int xres = 800, yres = 600;	//size of the Window
//int xres = 1280, yres = 1024;	//size of the Window
//int xres = 1920, yres = 1080;	//size of the Window

//Fog
GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
GLfloat density = 0.01;

//Light
GLfloat qaAmbientLight[] = {0.2,0.2,0.2,1.0};
GLfloat qaDiffuseLight[] = {0.8,0.8,0.8,1.0};
GLfloat qaSpecularLight[] = {1,1,1,1.0};
GLfloat qaLightPosition[] = {50,50,10,1.0};
GLfloat globalAmbient[] = { 0.2, 0.2, 0.2, 0.0 };

//Position and Direction of Camera
float xpos = 0, ypos = 0, zpos = 0;
float xrot = 0, yrot = 0, zrot = 0;
float xlook, zlook;

//Mouse-Help-Variables
int diffx, diffy;
float lastx, lasty; //position of the mouse-pointer
sf::Vector2i center(xres/2, yres/2);
float velocity = 0;

void keyPressed(unsigned char, int, int);
void keyPressedswitch (unsigned char, int, int);
void keyUp(unsigned char, int, int);
void keyUpswitch (unsigned char, int, int);

sf::Window DSWindow(sf::VideoMode(xres, yres, 32), "Ant Intelligence", sf::Style::Default, sf::ContextSettings(32));

void enableGlOptions (void)
{
	glEnable (GL_DEPTH_TEST);
   
	//FOG
	glEnable (GL_FOG);
	glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2
	glFogfv (GL_FOG_COLOR, fogColor);
	glFogf (GL_FOG_DENSITY, density);
	glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the nicest
	glShadeModel (GL_SMOOTH); //set the shader to smooth shader
}

// Replaces gluPerspective. Sets the frustum to perspective mode.
// fovY     - Field of vision in degrees in the y direction
// aspect   - Aspect ratio of the viewport
// zNear    - The near clipping distance
// zFar     - The far clipping distance

void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;
    fH = tan( fovY / 360 * pi ) * zNear;
    fW = fH * aspect;
    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}


////////////////////////////////////////////////////////////////////////////////////////

int main (int argc, char **argv)
{
	//Init with start Position
    xpos=9;
    ypos=9;
    zpos=15;
    xrot=50; //80°
    yrot=135; //135°

    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and writeca
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    perspectiveGL(40.f, (1.f * xres / yres), 1.f, 500.f);
	LoadTextures();

	while (DSWindow.isOpen()) // Game loop
	{		
		//calculate Time
		maintimer.stop();
		difTime = maintimer.getElapsedTimeInSec();
        if (difTime > 0.1) difTime = 0;	//remove first time
		gesTime += difTime;
		maintimer.start();
		


     	//Clear Screen and set OpenGL Settings
		DSWindow.setActive();
     	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     	glMatrixMode(GL_MODELVIEW);
     	glLoadIdentity();
 		glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
 		enableGlOptions();	//enable graphic-settings

        inputmanager(difTime);	//mve camera etc

        world();		//draw the "World

        levelDrawer1.drawBlocks();

        if(gameStart)
        {
            antHill1.ki();
            antHill1.antanimation();
        }

        DrawHUD();		//draw the HUD

     	// Finally, display the rendered frame on screen
     	DSWindow.display();
	}
return EXIT_SUCCESS;
}
