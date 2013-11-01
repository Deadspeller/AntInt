#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>

#include "anthill.h"
#include "ant.h"

class AntHill
{

public:
    std::vector <Ant> antVec;
	Ant tempAnt;
	int xposition, zposition;

    void spawnHill(int x, int z);
    void spawnAnt();
    void ki();
};

#endif
