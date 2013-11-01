#ifndef CAMERACALC_H
#define CAMERACALC_H

#include <cmath>

#include <SFML/Window.hpp>
#include <GL/glew.h>

extern int GP_LT ,GP_RT, GP_LB, GP_RB, GP_LStick, GP_RStick, GP_Dreieck;
extern int GP_Viereck, GP_X, GP_Kreis, GP_DUp, GP_DLeft, GP_DDown, GP_DRight;
extern int GP_Select, GP_Start, GP_XBox;

extern float gesTime;
extern float difTime;
extern float sprintPoints;
extern sf::Window DSWindow;
extern int leftClickAction;
extern float roundTime;

extern bool Key1, Key2, Key3, Key4, MoveForwardKey, MoveLeftKey, MoveBackwardKey, MoveRightKey, MoveSneakKey, MoveLaydownKey, MoveJumpKey, MoveSprintKey;
extern bool LControlKeyDown, YKeyDown, KKeyDown, IKeyDown, EscKeyDown, SpaceKeyDown, LeftClickDown;
extern int mouseScrollValue;

//Movement height
extern float camHeight;
extern float walkHeight;
extern float sneakHeight;
extern float layHeight;

//Movement speed
extern float actspeed;

//Cam speed
extern float mouseXspeed, mouseYspeed;
extern float joystickXspeed, joystickYspeed;

//Position and Direction of Camera
extern float xpos, ypos, zpos;
extern float xrot, yrot, zrot;

//Movement scale
extern float upview;

void cameracalc(float difTime);

#endif
