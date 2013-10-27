#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <GL/glew.h> // Include the GLEW header file 
#include "include/timer.h"
#include "include/texture.h"
#include "include/menu.h"
#include "include/hud.h"
#include "include/block.h"
#include "include/blockhandler.h"
#include "include/ant.h"
#include "include/anthandler.h"
#include "include/cameracalc.h"
#include "include/world.h"

#include <iostream>
#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

#include <GL/glew.h> // Include the GLEW header file  

using namespace std;


vector <vector <worldstruct> > worldvector(52, vector<worldstruct>(52)); //contains all informations about blocks, ants and food

extern int MouseScrollValue;

// Game Configurations
int leftclickaction = 2;
float roundTime = 1;

//Ants
const int maxants = 100;
const int maxblocks = 100;

//Classes
Ant antarray[maxants];
Block blockarray[maxblocks];

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
void keyPressedswitch(unsigned char, int, int);
void keyUp(unsigned char, int, int);
void keyUpswitch(unsigned char, int, int);




sf::Window DSWindow(sf::VideoMode(xres, yres, 32), "Ant Intelligence");

void drawswitch() //change between menu and game  !!NOT IN USE!!
{
	if(menuplay == 1);	// Draw the Game
	else 
	DrawMenu();			// Draw the Menu
}


void enableGlOptions (void) {
	glEnable (GL_DEPTH_TEST);
    //glEnable (GL_LIGHTING); //enable the lighting BUGGY
	//glEnable(GL_COLOR_MATERIAL);
    glEnable (GL_LIGHT0);
	glEnable (GL_LIGHT1);
	glEnable (GL_LIGHT2);
	glEnable( GL_NORMALIZE ); //for lightning. not really working
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT2, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT2, GL_SPECULAR, qaSpecularLight);
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, globalAmbient );
	glDisable(GL_COLOR_MATERIAL);
	glDisable (GL_LIGHTING);
	//FOG
	glEnable (GL_FOG);
	glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2
	glFogfv (GL_FOG_COLOR, fogColor);
	glFogf (GL_FOG_DENSITY, density);
	glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the nicest
	glShadeModel (GL_SMOOTH); //set the shader to smooth shader
}




////////////////////////////////////////////////////////////////////////////////////////


int main (int argc, char **argv) {
	//Init with start Position
	xpos=9;
 	ypos=15;
 	zpos=9;
	xrot=80; //70°
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
    gluPerspective(90.f, 1.f, 1.f, 500.f);
	LoadTextures();

    
	while (DSWindow.isOpen()) // Game loop
	{		

		//calculate Time
		maintimer.stop();
		difTime = maintimer.getElapsedTimeInSec();
		if(difTime > 0.1) difTime = 0;	//remove first time
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
		MoveForwardKey = KeyboardInput.isKeyPressed(sf::Keyboard::W);
		MoveLeftKey = KeyboardInput.isKeyPressed(sf::Keyboard::A);
		MoveBackwardKey = KeyboardInput.isKeyPressed(sf::Keyboard::S);
		MoveRightKey = KeyboardInput.isKeyPressed(sf::Keyboard::D);
		MoveSneakKey = KeyboardInput.isKeyPressed(sf::Keyboard::LControl);
		MoveSprintKey = KeyboardInput.isKeyPressed(sf::Keyboard::LShift);
		MoveLaydownKey = KeyboardInput.isKeyPressed(sf::Keyboard::Y);
		KKeyDown = KeyboardInput.isKeyPressed(sf::Keyboard::K);
		JKeyDown = KeyboardInput.isKeyPressed(sf::Keyboard::J);
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
		if(JoystickInput.getAxisPosition(0, sf::Joystick::Y) < 0) MoveForwardKey = true;
		if(JoystickInput.getAxisPosition(0, sf::Joystick::Y) > 0) MoveBackwardKey = true;
		if(JoystickInput.getAxisPosition(0, sf::Joystick::X) > 0) MoveRightKey = true;
		if(JoystickInput.getAxisPosition(0, sf::Joystick::X) < 0) MoveLeftKey = true;
	

		if(xrot < -90) xrot = -90;
		else
		yrot = yrot + joystickyspeed * 0.2 * JoystickInput.getAxisPosition(0, sf::Joystick::Z);

		if(xrot > 90) xrot = 90;
		else
		xrot = xrot - joystickxspeed * 0.1 * JoystickInput.getAxisPosition(0, sf::Joystick::R);


		while (DSWindow.pollEvent(Event))
		{
			if(Event.type == sf::Event::JoystickButtonPressed)
			{		
				if(JoystickInput.isButtonPressed(0, GP_RT)) AntHandler("handle");
			}
			DSWindow.setKeyRepeatEnabled(false);
			if (Event.type == sf::Event::KeyPressed)
			{
				if (Event.key.code == sf::Keyboard::K)
				{
					if(roundTime > 0.1)
					roundTime -= 0.05;
					cout<<"Zeit pro Runde: "<<roundTime<<endl;
				}
				if (Event.key.code == sf::Keyboard::J)
				{
					roundTime += 0.05;
					cout<<"Zeit pro Runde: "<<roundTime<<endl;
				}
			}

			// Close window : exit
          if (Event.type == sf::Event::Closed)
          	DSWindow.close();

		if(Event.type == sf::Event::MouseButtonPressed)	
		{
			if(Event.mouseButton.button == sf::Mouse::Left) 
			switch(leftclickaction)
			{
				case 1:	
						AntHandler("spawn");
						break;
				case 2: 
						BlockHandler("bspawn");
						break;
				case 3:
						BlockHandler("fspawn");
						break;
			}
		}

		if(Event.type = sf::Event::MouseWheelMoved)
		{
			MouseScrollValue = Event.mouseWheel.x - Event.mouseMove.x;
		}
		else
			MouseScrollValue = 0;
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

		AntHandler("move");	//move the Ants

		BlockHandler("draw");	//draw the Blocks

		world();		//draw the "World

		DrawHUD();		//draw the HUD




     	// Finally, display the rendered frame on screen
     	DSWindow.display();
	}

return EXIT_SUCCESS;
}
