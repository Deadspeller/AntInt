#ifndef LEVELDRAWER_H
#define LEVELDRAWER_H

#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SOIL/SOIL.h"

#include "anthill.h"
#include "levelmanager.h"
#include "texture.h"

void blockDraw(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);
void blockTextDraw(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);


extern LevelManager levelManager1;

class LevelDrawer
{

public:
    LevelDrawer();
    void drawBlocks();

}; //end Class

#endif
