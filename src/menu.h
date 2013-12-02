#ifndef MENU_H
#define MENU_H

#include <GL/glew.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "timer.h"

extern bool menukeyStates[]; // Keybuffer for multiple key-input
extern int menuplay, continueplay;
extern int drawoptions;
extern float selecty[4][2];
extern int menusel;
extern float hp;

extern Timer keytimer;
extern Timer waittimer;
extern float geskeyTime;
extern float geswaitTime;

void menukeyPressed (unsigned char key, int x, int y);
void menukeyUp (unsigned char key, int x, int y);
void menukeyOperations (void);

void DrawMenu();
void menukeyPressed (unsigned char key, int x, int y);
void menukeyUp (unsigned char key, int x, int y);
void menukeyOperations (void);

#endif
