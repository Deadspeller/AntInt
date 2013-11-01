#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>

#include "texture.h"
#include "timer.h"
#include "square.h"

class Square;
extern std::vector < std::vector <Square> > worldvector;

extern float antspeed;
extern float xpos, ypos, zpos;
extern float colobjects[6][4];

extern float roundTime;

using namespace std;

class Ant
{
public:
    vector <vector <int> > antworldvector;
    int antworldarray[3][3];
    bool collision;
    float difTime, gesTime;
    bool antalive;
    int foodbag;
    float yorigin, zorigin, xorigin; //where the ant started

    int xAntPosition, yAntPosition, zAntPosition; //Position of the Ant
    int oldxAntPosition, oldyAntPosition, oldzAntPosition; //Position of the Ant
    Timer AntTimer;

    int status;
    int done ;

    void ki();
    int antmove(int a);
    void antcollision();
    void nearcheck();
    void antspawn(int x, int z);
    int takeFood();

};	//end class

#endif // ANT_H
