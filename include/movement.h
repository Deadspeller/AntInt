

int GP_LT = 8,GP_RT = 9, GP_LB = 10, GP_RB = 11, GP_LStick = 1, GP_RStick = 2, GP_Dreieck = 12;
int GP_Viereck = 15, GP_X = 14, GP_Kreis = 13, GP_DUp = 4, GP_DLeft = 7, GP_DDown = 6, GP_DRight = 5;
int GP_Select = 0, GP_Start = 3, GP_XBox = 16;

extern float gesTime;
extern float difTime;
extern float sprintpoints;
extern sf::Window DSWindow;
extern int leftclickaction;

bool Key1, Key2, MoveForwardKey, MoveLeftKey, MoveBackwardKey, MoveRightKey, MoveSneakKey, MoveLaydownKey, MoveJumpKey, MoveSprintKey;
bool LControlKeyDown, YKeyDown, FKeyDown, GKeyDown, EscKeyDown, SpaceKeyDown, LeftClickDown;
int MouseScrollValue = 0;

	//Movement height
float camheight = 1.5;
float walkheight = 1.5;
float sneakheight = 1.0;
float layheight = 0.5;
	//Movement speed
float actspeed = 8;
	//Cam speed
float mousexspeed = 0.1, mouseyspeed = 0.1;
float joystickxspeed = 0.1, joystickyspeed = 0.1;
	//Movement scale

float upview;	

void movementcalc(float difTime)
{

	if (MoveForwardKey)
	{	
		float xrotrad, yrotrad, zrotrad;
    		yrotrad = (yrot / 180 * 3.141592654f);
    		xrotrad = (xrot / 180 * 3.141592654f); 
		upview = float(sin(xrotrad));

		//x-richtungsgeschw.
		xpos += float(sin(yrotrad))*actspeed*difTime ;

		//z-richtungsgeschw.
		zpos -= float(cos(yrotrad))*actspeed*difTime ;

	}


	if (MoveBackwardKey)
	{	float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f); 
		xpos -= float(sin(yrotrad))*actspeed*difTime;
		zpos += float(cos(yrotrad))*actspeed*difTime;
	}

	if (MoveRightKey)
	{	float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos += float(cos(yrotrad)) * actspeed*difTime;
		zpos += float(sin(yrotrad)) * actspeed*difTime;
	}

	if (MoveLeftKey)
	{	float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos -= float(cos(yrotrad)) * actspeed*difTime;
		zpos -= float(sin(yrotrad)) * actspeed*difTime;
	}

	if(MouseScrollValue!=0)
	{
		//cout<<"Mausrad gedreht";
		//xpos += MouseScrollValue;
		MouseScrollValue = 0;
	}
	
	if (Key1)
	{	
		leftclickaction = 1;
	}

	if (Key2)
	{	
		leftclickaction = 2;
	}


	if (FKeyDown)
	{	
	}

	if (GKeyDown)
	{	
	}
		
	if (EscKeyDown)
	{	 DSWindow.close();
	}
}
