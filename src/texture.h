#ifndef TEX_H
#define TEX_H

#include "SOIL/SOIL.h"
#include <GL/glew.h>

#include <iostream>

using namespace std;

extern GLuint tex_grass;
extern GLuint tex_antfeet;
extern GLuint tex_antbody;
extern GLuint tex_antback;
extern GLuint tex_wood_horizontal;
extern GLuint tex_wood_vertical;
extern GLuint tex_hill;

int LoadTextures();

#endif
