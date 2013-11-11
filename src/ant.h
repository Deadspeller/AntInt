#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>

#include "texture.h"
#include "timer.h"
#include "square.h"
#include "pathfind.h"

class PathFind;
class Square;
class AntHill;

extern std::vector < std::vector <Square> > worldvector;
extern size_t xworldsize, zworldsize;

extern float antspeed;
extern float xpos, ypos, zpos;
extern float colobjects[6][4];
extern float roundTime;

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
    vector <vector <Square> > antMapVec;
    vector <vector <Square> > antViewVec;

    int antViewRows, antViewColumns;
    int foodfound;
    int startdirection;

private:
    bool done;
    int status;
    int waytick;
    int lastmove;
    int nextmove;
    int followingPath;

    bool collision;
    float difTime, gesTime;

    int foodbag;
    float yorigin, zorigin, xorigin; //where the ant started

    int xAntPosition, yAntPosition, zAntPosition; //Position of the Ant
    int oldxAntPosition, oldyAntPosition, oldzAntPosition; //Position of the Ant
    Timer AntTimer;

    PathFind *pathfinder;
    std::string path;

    int antmove(size_t a);
    void antcollision();
    void nearcheck();
    void updateMap();

    int takeFood();
    int bringFood();

    void searchfood();
    void findWayBack();

};	//end class

#endif // ANT_H
