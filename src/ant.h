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
class AntHill;

extern float antspeed;
extern float xpos, ypos, zpos;
extern float colobjects[6][4];
extern float roundTime;

extern int xworldsize, zworldsize;

using namespace std;

class Ant
{

public:
    Ant();
    AntHill *anthillpointer;
    vector <vector <int> > antworldvector;
    int *xhillorigin, *zhillorigin, *hillfood;

    bool antalive;

    void antspawn(int x, int z);
    void ki();

private:
    vector <vector <Square> > antWorldVec;
    vector <vector <Square> > antMapVec;

    int antViewRows, antViewColumns;

    int i;
    int lastmove;
    int foodfound;
    int done;
    int status;
    int startdirection;

    bool collision;
    float difTime, gesTime;

    int foodbag;
    float yorigin, zorigin, xorigin; //where the ant started

    int xAntPosition, yAntPosition, zAntPosition; //Position of the Ant
    int oldxAntPosition, oldyAntPosition, oldzAntPosition; //Position of the Ant
    Timer AntTimer;

    int antmove(int a);
    void antcollision();
    void nearcheck();
    void updateMap();

    int takeFood();
    int bringFood();

};	//end class

#endif // ANT_H
