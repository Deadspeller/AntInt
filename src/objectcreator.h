#ifndef OBJECTCREATOR_H
#define OBJECTCREATOR_H

#include <vector>
#include <iostream>

#include "square.h"

extern std::vector < std::vector <Square> > worldvector;
extern size_t xworldsize, zworldsize;


class ObjectCreator        //class for all classes, Wall-Blocks and Food-Blocks
{

public:        
    void createBlock(size_t xwert, size_t zwert, int blocktype);
    void createHill(size_t x, size_t z);
    void createAnt(size_t xpos, size_t zpos);
                
}; //end Class

#endif
