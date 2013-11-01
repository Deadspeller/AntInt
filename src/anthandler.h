#ifndef ANTHANDLER_H
#define ANTHANDLER_H

#include <vector> 
#include <iostream>

#include "anthill.h"

using namespace std;

extern float camHeight;
extern float xpos, zpos;
extern float yrot, xrot;
extern const int maxants;
extern class Ant antarray[100];
extern class AntHill antHill1;

void AntHandler(string);

#endif
