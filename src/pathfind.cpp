#include "pathfind.h"
#include <queue>
#include "node.h"
#include <iostream>
#include <stdlib.h>

/** Pathfinding (A* algo) using Manhatten heuristics and assuming a monotonic, consistent
*   heuristic (the enemies do not change position)
*
*   TODO: add variable terrain cost
**/

//dimensions
const int horizontalSize = 20;
const int verticalSize = 20;

//nodes sets
static int closedNodes[horizontalSize][verticalSize]; //the set of nodes already evaluated
static int openNodes[horizontalSize][verticalSize]; // the set of nodes to be evaluated; initialy only containing start node
static int dir_map[horizontalSize][verticalSize]; //map of directions (contains parents-children connection)

//directions
const int dir=4;
static int dirX[dir]={1,0,-1,0};
static int dirY[dir]={0,1,0,-1};

//test class
static int map[horizontalSize][verticalSize]; //map of navigated nodes
pathFind::pathFind(){
    //test
    srand(time(NULL));
    //create empty map
    for (int y=0;y<verticalSize;y++){
        for (int x=0;x<horizontalSize;x++){
            map[x][y]=0;
        }
    }
    //fillout matrix
    for (int x=horizontalSize/8;x<horizontalSize*7/8;x++){
        map[x][verticalSize/2]=1;
    }
    for (int y=verticalSize/8;y<verticalSize*7/8;y++){
        map[horizontalSize/2][y]=1;
    }

    //randomly select start and finish locations
    int xA,yA,xB,yB;
    int n=horizontalSize;
    int m=verticalSize;

    xA=6;
    yA=5;

    xB = 14;
    yB = 12;

    std::cout <<"Map Size (X,Y): "<<n<<","<<m<<std::endl;
    std::cout<<"Start: "<<xA<<","<<yA<<std::endl;
    std::cout<<"Finish: "<<xB<<","<<yB<<std::endl;


    // get the route
    clock_t start = clock();
    string route=calculatePath(xA, yA, xB, yB);
    if(route=="") std::cout <<"An empty route generated!"<<std::endl;
    clock_t end = clock();
    double time_elapsed = double(end - start);
    std::cout<<"Time to calculate the route (ms): "<<time_elapsed<<std::endl;
    std::cout<<"Route:"<<std::endl;
    std::cout<<route<<std::endl<<std::endl;
}

string pathFind::calculatePath(const int & xStart, const int & yStart,const int & xFinish, const int & yFinish){
    /** why do we maintain a priority queue?
    *   it's for maintaining the open list: everytime we acces the open list we need to find the node with the lowest
    *   fscore. A priority queue is a sorted list so we simply have to grab (pop) the first item of the list everytime
    *   we need a lower fscore.
    *
    *   A priority queue is a data structure in which only the largest element can be retrieved (popped).
    *   It's problem is that finding an node in the queue is a slow operation.
    **/
    std::priority_queue<node> pq[2]; //we define 2 priority list which is needed for our priority change of a node 'algo'
    static int index; //static and global variables are initialized to 0
    static node *currentNode;
    static node *neighborNode;
    //first reset maps
    resetMaps();

    //create start node
    static node * startNode;
    startNode= new node(xStart,yStart,0,0);
    startNode->updatePriority(xFinish, yFinish);

    // push it into the priority queue
    pq[index].push(*startNode);

    //add it to the list of open nodes
    openNodes[0][0] = startNode->getPriority();

    //A* search
    //while priority queue is not empty; continue
    while(!pq[index].empty()){
        //get current node with the higest priority from the priority list
        //in first instance this is the start node
        currentNode = new node(pq[index].top().getxPos(),
                               pq[index].top().getyPos(),
                               pq[index].top().getDistance(),
                               pq[index].top().getPriority());
        //remove node from priority queue
        pq[index].pop();
        openNodes[currentNode->getxPos()][currentNode->getyPos()]=0; //remove node from open list
        closedNodes[currentNode->getxPos()][currentNode->getyPos()]=1; //add current to closed list

        //if current node = goal => finished => retrace route back using parents nodes
        if (currentNode->getxPos()==xFinish && currentNode->getyPos()==yFinish){
            //quit searching if goal is reached
            //return generated path from finish to start
            string path="";
            int x,y,direction; //in cpp you don't need to declare variables at the top compared to c
            //currentNode is now the goalNode
            x=currentNode->getxPos();
            y=currentNode->getyPos();
            while (!(x==xStart && y==yStart)){
                /** We start at goal and work backwards moving from node to parent
                 *  which will take us to the starting node
                **/
                direction=dir_map[x][y];
                path =(direction+dir/2)%dir+path; //we work our way back
                //iterate trough our dir_map using our defined directions
                x+=dirX[direction];
                y+=dirY[direction];
            }

            //garbage collection; the memory allocated with 'new' should be freed to avoid memory leaks
            delete currentNode;
            while (!pq[index].empty()){
                pq[index].pop();
            }
            return path;

            //return path;
        } else {
            //add all possible neighbors to the openlist + define parents for later tracing back
            //(four directions (int dir): up, down, left & right); but we want to make it
            //as extendable as possible
            for (int i=0; i<dir; i++){
                //define new x & y coord for neighbor
                //we do this because we want to preform some checks before making this neighbore node
                int neighborX = currentNode->getxPos()+dirX[i];
                int neighborY = currentNode->getyPos()+dirY[i];
                //check boundaries
                //ignore if on closed list (was already evaluted) or if unwalkable (currently not implemented)

                if (!(neighborX <0 || neighborY <0 || neighborX > horizontalSize || neighborY > verticalSize ||
                      closedNodes[neighborX][neighborY]==1)){
                    //ok -> generate neighbor node
                    neighborNode = new node (neighborX,neighborY,currentNode->getDistance(),currentNode->getPriority());
                    //calculate the fscore of the node
                    neighborNode->updatePriority(xFinish,yFinish);
                    neighborNode->updateDistance();

                    //if neighbor not in openset => add it
                    if(openNodes[neighborX][neighborY]==0){
                        //add it to open set
                        openNodes[neighborX][neighborY]=neighborNode->getPriority();
                        //add it to the priority queue (by dereferencing our neighborNode object
                        //pq is of type node; push inserts a new element;
                        //the content is initialized as a copy
                        pq[index].push(*neighborNode);
                        //set the parent to the node we are currently looking at
                        dir_map[neighborX][neighborY]=(i+dir/2)%dir;

                    //if neighbor is already on open set
                    //check if path to that node is a better one (=lower gscore) if we use the current node to get there
                    } else if(openNodes[neighborX][neighborY]>neighborNode->getPriority()) {
                        /** lower gscore: change parent of the neighbore node to the select square
                        *   recalculate fscore
                        *   the value of the fscore should also be changed inside the node which resides inside our priority queue
                        *   however as mentioned before this is a very slow operation (is going to be the bottleneck of this implemention probably)
                        *   we will have to manuall scan for the right node and than change it.
                        *
                        *   this check is very much needed, but the number of times this if condition is true is limited
                        **/

                        //update fscore inside the open list
                        openNodes[neighborX][neighborY]=neighborNode->getPriority();
                        //update the parent node
                        dir_map[neighborX][neighborY]=(i+dir/2)%dir;

                        //we copy the nodes from one queue to the other
                        //except the -old-current node will be ignored
                        while (!((pq[index].top().getxPos()==neighborX) && (pq[index].top().getyPos()==neighborY))){
                            pq[1-index].push(pq[index].top());
                            pq[index].pop();
                        }
                        pq[index].pop(); //remove the -old-current node

                        /** ?? **/
                        if(pq[index].size()>pq[1-index].size()){ //??? is this extra check necessary?
                            index=1-index; //index switch 1->0 or 0->1
                        }

                        while(!pq[index].empty()){
                            pq[1-index].push(pq[index].top());
                            pq[index].pop();
                        }
                        /** ?? **/


                        index=1-index; //index switch 1->0 or 0->1
                        pq[index].push(*neighborNode); //and the -new-current node will be pushed in instead
                    } else delete neighborNode;

                }
            }

            delete currentNode;
        }

    } return ""; //no path found
}

void pathFind::resetMaps(){
    for (int y=0;y<horizontalSize;y++){
        for (int x=0;x<verticalSize;x++){
            closedNodes[x][y]=0;
            openNodes[x][y]=0;
        }
    }
}
