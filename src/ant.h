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
extern float AntSpeed;
extern float lifeTime;

using namespace std;

class Ant
{

public:
    Ant();
    AntHill *anthillpointer;
    vector <vector <int> > antworldvector;
    int *xhillorigin, *zhillorigin, *hillfood;
    int *nextfoodx, *nextfoodz, *nextfoodmanhattan;

    bool antalive;
    float antLifeTime;
    bool antwarning;

    void antspawn(int x, int z);
    void ki();
    void setNextFood(int x, int z, int foodleft);
    vector <vector <Square> > antMapVec;
    vector <vector <Square> > antViewVec;

    int antViewRadius;
    int foodfound;
    int startdirection;
    int movedirection;
    int xAntPosition, yAntPosition, zAntPosition; //Position of the Ant
    float xAntAnimPosition, yAntAnimPosition, zAntAnimPosition;
    int oldxAntPosition, oldyAntPosition, oldzAntPosition; //Position of the Ant


private:
    bool done;
    int waytick;
    int nextmove;
    int lastmove;
    int followingPath;

    int nextx, nextz;
    int xwalkpos, zwalkpos;

    int xFoodPos, yFoodPos;
    int lastFoodValue;
    int foodleft;
    bool foodInSight;

    bool collision;
    float difTime, gesTime;

    int foodbag;
    float yorigin, zorigin, xorigin; //where the ant started



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
    bool findWayTo(size_t xTo, size_t yTo);

    enum myStati {SEARCH,TAKE,GOHOME,PUT,GOFOOD} status;

};	//end class

#endif // ANT_H
