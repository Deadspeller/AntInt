#include "inputmanager.h"

int GP_LT = 8,GP_RT = 9, GP_LB = 10, GP_RB = 11, GP_LStick = 1, GP_RStick = 2, GP_Dreieck = 12;
int GP_Viereck = 15, GP_X = 14, GP_Kreis = 13, GP_DUp = 4, GP_DLeft = 7, GP_DDown = 6, GP_DRight = 5;
int GP_Select = 0, GP_Start = 3, GP_XBox = 16;

bool Key1, Key2, Key3, Key4, MoveForwardKey, MoveLeftKey, MoveBackwardKey, MoveRightKey, MoveSneakKey, MoveLaydownKey, MoveJumpKey, MoveSprintKey;
bool LControlKeyDown, YKeyDown, KKeyDown, IKeyDown, EscKeyDown, SpaceKeyDown, LeftClickDown;
int mouseScrollValue = 0;

//Movement height
float camHeight = 1.5;
float walkHeight = 1.5;
float sneakHeight = 1.0;
float layHeight = 0.5;

//Movement speed
float actspeed = 8;

//Cam speed
float mouseXspeed = 0.1, mouseYspeed = 0.1;
float joystickXspeed = 0.1, joystickYspeed = 0.1;

//Movement scale
float upview;

void cameracalc(float difTime)
{

    if (MoveForwardKey)
    {
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f);
        upview = float(sin(xrotrad));

        //x-richtungsgeschw.
        xpos += float(sin(yrotrad)) * actspeed * difTime ;

        //z-richtungsgeschw.
        zpos -= float(cos(yrotrad)) * actspeed * difTime ;

    }

    if (MoveBackwardKey)
    {	float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f);
        xpos -= float(sin(yrotrad)) * actspeed * difTime;
        zpos += float(cos(yrotrad)) * actspeed * difTime;
    }

    if (MoveRightKey)
    {	float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xpos += float(cos(yrotrad)) * actspeed * difTime;
        zpos += float(sin(yrotrad)) * actspeed * difTime;
    }

    if (MoveLeftKey)
    {	float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xpos -= float(cos(yrotrad)) * actspeed*difTime;
        zpos -= float(sin(yrotrad)) * actspeed*difTime;
    }

    if (mouseScrollValue != 0)
    {
        //cout<<"Mausrad gedreht";
        //xpos += MouseScrollValue;
        mouseScrollValue = 0;
    }

    if (Key1)
        leftClickAction = 1;

    if (Key2)
        leftClickAction = 2;

    if (Key3)
        leftClickAction = 3;

    if (Key4)
        leftClickAction = 4;

    if (KKeyDown)
    {}

    if (IKeyDown)
    {
        //roundTime = 0;
    }

    if (EscKeyDown)
        DSWindow.close();

    glRotatef(xrot,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,-ypos,-zpos); //translate the screen to the position of our camera
}
