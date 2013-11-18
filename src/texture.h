#ifndef TEX_H
#define TEX_H

#include "SOIL/SOIL.h"
#include <GL/glew.h>

#include <iostream>

using namespace std;

extern GLuint tex_grass;
extern GLuint tex_ant;
extern GLuint tex_antbody;
extern GLuint tex_antback;
extern GLuint tex_wood_horizontal;
extern GLuint tex_wood_vertical;
extern GLuint tex_hill;
extern GLuint tex_honeycomb100;
extern GLuint tex_honeycomb90;
extern GLuint tex_honeycomb80;
extern GLuint tex_honeycomb60;
extern GLuint tex_honeycomb50;
extern GLuint tex_honeycomb30;
extern GLuint tex_honeycomb10;
extern GLuint tex_honeycomb5;

int LoadTextures();

#endif
