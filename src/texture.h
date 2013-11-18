#ifndef TEX_H
#define TEX_H

#include "SOIL/SOIL.h"
#include <GL/glew.h>

#include <iostream>

using namespace std;

extern GLuint tex_grass;
extern GLuint tex_ant;
extern GLuint tex_wood_horizontal;
extern GLuint tex_wood_vertical;
extern GLuint tex_hill;

int LoadTextures();

#endif
