#ifndef PATHFIND_H
#define PATHFIND_H

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

#include "square.h"
#include "node.h"

class Square;
class Node;
class AntHill;
class Ant;
extern AntHill antHill1;
extern std::vector < std::vector <Square> > worldvector;

using std::string;

class PathFind
{
public:
    PathFind();
    void updateMap(Ant *);
    void resetMaps();

    string calculatePath(const int &, const int & ,const int & , const int & );
private:

};

#endif
