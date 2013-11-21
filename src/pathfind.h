#ifndef PATHFIND_H
#define PATHFIND_H

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <memory>

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
    const int dir;
    std::vector<int> dirX;
    std::vector<int> dirY;
    std::vector< std::vector<int> > closedNodes; //the set of nodes already evaluated
    std::vector< std::vector<int> > openNodes; // the set of nodes to be evaluated; initialy only containing start node
    std::vector< std::vector<int> > map; //map of navigated nodes
    std::vector< std::vector<int> > dir_map; //map of directions (contains parents-children connection)
};

#endif
