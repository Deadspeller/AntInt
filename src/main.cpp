#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <list>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

#include "ant.h"
#include "anthandler.h"
#include "cameracalc.h"
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

vector <vector <Square> > worldvector(52, vector<Square>(52)); //contains all informations about blocks, ants and food

extern int mouseScrollValue;

// Game Configurations
int leftClickAction = 2;
float roundTime = 1;

//world
int xworldsize = 30;
int zworldsize = 30;

//Ants
const int maxants = 100;
const int maxblocks = 100;

//Classes
Ant antarray[maxants];
Square blockarray[maxblocks];
ObjectCreator objectCreator1;
LevelDrawer levelDrawer1;
LevelManager levelManager1;
AntHill antHill1;
float gesTime;
float difTime;

Timer maintimer;

//--OpenGL Variables--

int xres = 640, yres = 480;	//size of the Window

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

void drawswitch () //change between menu and game  !!NOT IN USE!!
{
    if (menuplay == 1);	// Draw the Game
	else 
	DrawMenu();			// Draw the Menu
}


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
 	zpos=9;
	xrot=80; //80°
	yrot=135;	//135°

   // Set the color and depth clear values
   glClearDepth(1.f);
   glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    perspectiveGL(90.f, 1.f, 1.f, 500.f);
	LoadTextures();

    
	while (DSWindow.isOpen()) // Game loop
	{		
		//calculate Time
		maintimer.stop();
		difTime = maintimer.getElapsedTimeInSec();
        if (difTime > 0.1) difTime = 0;	//remove first time
		gesTime += difTime;
		maintimer.start();
		
		//check for Inputs
		sf::Event Event;
		sf::Keyboard KeyboardInput;
		sf::Joystick JoystickInput;
		sf::Mouse MouseInput;
		//Keyboard
		Key1 = KeyboardInput.isKeyPressed(sf::Keyboard::Num1);
		Key2 = KeyboardInput.isKeyPressed(sf::Keyboard::Num2);
		Key3 = KeyboardInput.isKeyPressed(sf::Keyboard::Num3);
		Key4 = KeyboardInput.isKeyPressed(sf::Keyboard::Num4);
		MoveForwardKey = KeyboardInput.isKeyPressed(sf::Keyboard::W);
		MoveLeftKey = KeyboardInput.isKeyPressed(sf::Keyboard::A);
		MoveBackwardKey = KeyboardInput.isKeyPressed(sf::Keyboard::S);
		MoveRightKey = KeyboardInput.isKeyPressed(sf::Keyboard::D);
		MoveSneakKey = KeyboardInput.isKeyPressed(sf::Keyboard::LControl);
		MoveSprintKey = KeyboardInput.isKeyPressed(sf::Keyboard::LShift);
		MoveLaydownKey = KeyboardInput.isKeyPressed(sf::Keyboard::Y);
		IKeyDown = KeyboardInput.isKeyPressed(sf::Keyboard::I);
		KKeyDown = KeyboardInput.isKeyPressed(sf::Keyboard::K);
		EscKeyDown = KeyboardInput.isKeyPressed(sf::Keyboard::Escape);
		MoveJumpKey = KeyboardInput.isKeyPressed(sf::Keyboard::Space);
		//Joystick
		MoveForwardKey |= JoystickInput.isButtonPressed(0, GP_DUp);
		MoveLeftKey |= JoystickInput.isButtonPressed(0, GP_DLeft);
		MoveBackwardKey |= JoystickInput.isButtonPressed(0, GP_DDown);
		MoveRightKey |= JoystickInput.isButtonPressed(0, GP_DRight);
		MoveSneakKey |= JoystickInput.isButtonPressed(0, GP_LStick);
		MoveSprintKey |= JoystickInput.isButtonPressed(0, GP_LT);
		MoveJumpKey |= JoystickInput.isButtonPressed(0, GP_LB);
		//Mouse
		LeftClickDown = MouseInput.isButtonPressed(sf::Mouse::Left);

        //Joystick Axis
        if (JoystickInput.getAxisPosition(0, sf::Joystick::Y) < 0) MoveForwardKey = true;
        if (JoystickInput.getAxisPosition(0, sf::Joystick::Y) > 0) MoveBackwardKey = true;
        if (JoystickInput.getAxisPosition(0, sf::Joystick::X) > 0) MoveRightKey = true;
        if (JoystickInput.getAxisPosition(0, sf::Joystick::X) < 0) MoveLeftKey = true;
	
        if (xrot < -90)
            xrot = -90;
		else
            yrot = yrot + joystickYspeed * 0.2 * JoystickInput.getAxisPosition(0, sf::Joystick::Z);

        if (xrot > 90)
            xrot = 90;
		else
            xrot = xrot - joystickXspeed * 0.1 * JoystickInput.getAxisPosition(0, sf::Joystick::R);

		while (DSWindow.pollEvent(Event))
		{
            if (Event.type == sf::Event::JoystickButtonPressed)
			{		
                if (JoystickInput.isButtonPressed(0, GP_RT)) AntHandler("handle");
			}
			DSWindow.setKeyRepeatEnabled(false);
			if (Event.type == sf::Event::KeyPressed)
			{
                if (Event.key.code == sf::Keyboard::K)
				{
//                    levelManager1.saveFile();
                    if (roundTime > 0.1)
                        roundTime -= 0.05;
					cout<<"Zeit pro Runde: "<<roundTime<<endl;
				}

                if (Event.key.code == sf::Keyboard::J)
				{
//                    levelManager1.loadFile();
					roundTime += 0.05;
					cout<<"Zeit pro Runde: "<<roundTime<<endl;
				}

                if (Event.key.code == sf::Keyboard::Z)
				{
                    if (ypos > 4)
                        ypos -= 0.5;
				}

                if (Event.key.code == sf::Keyboard::U)
				{
					ypos += 0.5;
				}

                if (Event.key.code == sf::Keyboard::T)
				{
					cout<<"Anthill Spawn"<<endl;
					antHill1.ki();
				}
            }

            // Close window : exit
            if (Event.type == sf::Event::Closed)
                DSWindow.close();

            if (Event.type == sf::Event::MouseButtonPressed)
            {
                if (Event.mouseButton.button == sf::Mouse::Left)
                switch (leftClickAction)
                {
                    case 1:
                            AntHandler("spawn");
                            break;
                    case 2:
                            objectCreator1.createBlock(round(xpos+1), round(zpos+1), 1);
                            break;
                    case 3:
                            objectCreator1.createBlock(round(xpos+1), round(zpos+1), 2);
                            break;
                    case 4:
                            objectCreator1.createHill(round(xpos+1), round(zpos+1));
                            antHill1.spawnHill(round(xpos)+1, round(zpos)+1);
                            break;
                }
            }

            if (Event.type = sf::Event::MouseWheelMoved)
                mouseScrollValue = Event.mouseWheel.x - Event.mouseMove.x;
            else
                mouseScrollValue = 0;
		}

///////////////////End Input////////////////

     	//Clear Screen and set OpenGL Settings
		DSWindow.setActive();
     	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     	glMatrixMode(GL_MODELVIEW);
     	glLoadIdentity();
 		glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
 		enableGlOptions();	//enable graphic-settings

		cameracalc(difTime);	//move the camera
		
		world();		//draw the "World

		levelDrawer1.drawBlocks();

		AntHandler("move");	//move the Ants

		DrawHUD();		//draw the HUD

     	// Finally, display the rendered frame on screen
     	DSWindow.display();
	}
return EXIT_SUCCESS;
}
