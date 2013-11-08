#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/** constructor **/
node::node(int x,int y, int d,int p)
{
    xPos=x;
    yPos=y;
    distance=d;
    priority=p;
}

/** getters for variables **/
//current node xPosition
int node::getxPos() const {
    return xPos;
}

//current node yPosition
int node::getyPos() const {
    return yPos;
}

//gscore
int node::getDistance() const {
    return distance;
}

//fscore
int node::getPriority() const {
    return priority;
}

/** Updates the priority; the lower the fscore the higer the priority
 *  the fscore is the sum of:
 *  -path-cost (gscore) (which is the distance from the starting node to the current node)
 *  -heuristic estimate (hscore) (which is an estimate of the distance from the current node to the destination node)
 *
**/
void node::updatePriority(const int & xDest, const int & yDest){
    priority = distance + estimateDistance(xDest,yDest)*10;
}

void node::updateDistance(){//const int & direction
    distance +=10;
}


/** Estimate function for the remaining distance to the goal
*   here it's based on the Manhattan distance;
*   which is the distance between two points in a grid based on a strictly horizontal & veritcal path;
*   => sum of vertical & horizontal components
**/
const int & node::estimateDistance(const int & xDest, const int & yDest) const{
    static int xDistance,yDistance,totalDistance;
    xDistance=xDest-xPos;
    yDistance=yDest-yPos;

    totalDistance=abs(xDistance)+abs(yDistance);

    return (totalDistance);
}

/** class functor (I think) to compare elements using:
 *  operator overloading: "<" gets overloaded which we are going to use in our priority queue
*   to determine priority of a node in our queue;
*   returns true if node a has a lower fscore compared to node b
*
*   there is an ambiguity here: < -- >; better to make both >
*   also prototype is now friend which could probably be replaced with this for the first
*   argument; it advantage is that because of the friend function the operand order can be reversed
*   this doesn't really looks to favor our application; so should I use it or not?
**/
bool operator(const node & a, const node & b){
    return a.getPriority() > b.getPriority();
}
