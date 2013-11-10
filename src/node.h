#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

class Node
{

public:
    Node(int, int, int, int);
    int getxPos() const;
    int getyPos() const;
    int getDistance() const;
    int getPriority() const;
    void updatePriority(const int&, const int&);
    void updateDistance();
    const int & estimateDistance(const int&, const int&) const;

private:
    int xPos;
    int yPos;
    int distance;
    int priority;

};

bool operator<(const Node & a, const Node & b);

#endif
