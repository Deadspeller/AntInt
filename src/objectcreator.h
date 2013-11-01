#ifndef OBJECTCREATOR_H
#define OBJECTCREATOR_H

#include <vector>
#include <iostream>

#include "square.h"

extern std::vector < std::vector <Square> > worldvector;
extern int xworldsize, zworldsize;


class ObjectCreator        //class for all classes, Wall-Blocks and Food-Blocks
{

public:        
    void createBlock(float xwert, float zwert, int blocktype);
    void createHill(int x, int z);
    void createAnt(float xpos, float zpos);
                
}; //end Class

#endif
