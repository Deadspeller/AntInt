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

void inputmanager(float difTime)
{

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

    //calculate where the user is looking at
    xlook = round ( xpos + (abs(cos(yrot*3.14/180))) * (tan((90-xrot)*3.14/180)*ypos) );
    zlook = round ( zpos + (abs(cos(yrot*3.14/180))) * (tan((90-xrot)*3.14/180)*ypos) );

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
                if (roundTime > 0.1)
                    roundTime -= 0.05;
                cout<<"Zeit pro Runde: "<<roundTime<<endl;
            }

            if (Event.key.code == sf::Keyboard::J)
            {
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
            if (Event.key.code == sf::Keyboard::L)
            {
                levelManager1.loadFile();
            }
            if (Event.key.code == sf::Keyboard::O)
            {
                levelManager1.saveFile();
            }
            if (Event.key.code == sf::Keyboard::B)
            {
                if(!gameStart)gameStart = true;
                else gameStart = false;
            }
            if(Event.key.code == sf::Keyboard::P)
            {
                std::ofstream antViewFile;
                cout<<"File Output"<<endl;
                antViewFile.open ("antview.txt");
                antViewFile << "Ant Mind Map" << std::endl;
                antViewFile << "Map size: " << antHill1.antVec[0].antMapVec.size() << " X " << antHill1.antVec[0].antMapVec[0].size() << std::endl;

                for (size_t a = 0; a < antHill1.antVec[0].antMapVec.size(); a++)
                {
                    antViewFile << std::endl;
                    for (size_t b = 0; b < antHill1.antVec[0].antMapVec[0].size(); b++)
                        antViewFile << antHill1.antVec[0].antMapVec[a][b].block << "|";
                }
                antViewFile.close();
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
                        objectCreator1.createBlock(xlook, zlook, 1);
                        break;
                case 3:
                        objectCreator1.createBlock(xlook, zlook, 2);
                        break;
                case 4:
                        //objectCreator1.createHill(round(xpos+1), round(zpos+1));
                        antHill1.setHill(xlook, zlook);
                        objectCreator1.createHill(antHill1.xposition, antHill1.zposition);
                        break;
            }
        }

        if ( (Event.type = sf::Event::MouseWheelMoved) )
            mouseScrollValue = Event.mouseWheel.x - Event.mouseMove.x;
        else
            mouseScrollValue = 0;
    }

///////////////////End Input////////////////


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
