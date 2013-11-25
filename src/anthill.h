#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>

#include "anthill.h"
#include "ant.h"

extern int maxAnts;
extern float roundTime;

class AntHill
{    
public:
    std::vector <Ant> antVec;
	Ant tempAnt;
	int xposition, zposition;
    int food;
    int nextfoodx, nextfoodz, nextfoodmanhattan;

    void setHill(size_t x, size_t z);
    void spawnAnt();
    void ki();
    void moveAnts();
    void antanimation();
    AntHill(int, int);
};

#endif
