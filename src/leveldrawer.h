#ifndef LEVELDRAWER_H
#define LEVELDRAWER_H

#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SOIL/SOIL.h"

#include "levelmanager.h"
#include "texture.h"

extern LevelManager levelManager1;

class LevelDrawer
{

public:
    LevelDrawer();
    void drawBlocks();
                
}; //end Class

#endif
