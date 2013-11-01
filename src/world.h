#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <GL/glew.h>

#include "square.h"
#include "texture.h"

extern std::vector < std::vector <Square> > worldvector;
extern int xworldsize, zworldsize;

void world();

#endif
