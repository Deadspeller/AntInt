#include "anthill.h"

void AntHill::ki()
{
    spawnAnt();
}

void AntHill::spawnAnt()
{
    antVec.push_back(tempAnt);
    antVec[antVec.size()-1].antspawn(xposition, zposition);
}

void AntHill::spawnHill(int x, int z)
{
    xposition = x;
    zposition = z;
}
