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
    int food;

    void setHill(size_t x, size_t z);
    void spawnAnt();
    void ki();
    AntHill(int, int);
};

#endif
