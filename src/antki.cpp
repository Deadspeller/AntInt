#include "ant.h"
#include "pathfind.h"
#include "antki.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

extern int startdirection,antViewRows, antViewColumns;
extern size_t xworldsize, zworldsize;


void Ant::ki() //TODO: only call ki() once a round! (move drawing to levelDrawer)
{
    nearcheck();

    if(done)    //ant was moved, now calculate new.
    {

        switch (status)
        {

            case SEARCH:     //suche futter
                    searchfood();
                    if(antMapVec[xAntPosition][zAntPosition].food > 0 )
                    {
                        status = TAKE;
                        nextmove = 9;
                    }
                    break;

            case TAKE:     //futter aufnehmen
                    if (takeFood())
                        status = GOHOME;
                    else
                        status = SEARCH;
                    break;

            case GOHOME:     //A* zum Bau
                    findWayTo(*xhillorigin, *zhillorigin);
                    if(*xhillorigin == xAntPosition && *zhillorigin == zAntPosition)
                    {
                        status = PUT;
                        nextmove = 9;
                    }
                    break;

            case PUT:     //Futter ablegen
                    if(bringFood())
                    {
                        cout<<"food zurückgebracht"<<endl;
                        status = GOFOOD;
                        waytick = 0;
                    }
                    break;

            case GOFOOD:     //A* zum Futter
                    findWayTo(xFoodPos, yFoodpos);
                    if(xFoodPos == xAntPosition && yFoodpos == zAntPosition)
                    {
                        status = TAKE;
                        nextmove = 9;
                    }
                    break;

            default:
                    status = SEARCH;
                    cout << "default state, shouldnt happen!" << endl;
                    break;
        }
    }

    done = antmove(nextmove);
}


int nextx, nextz;
int xwalkpos, zwalkpos;
void Ant::searchfood()
{

    if(waytick>=3 || (xAntPosition == nextx && zAntPosition == nextz))
    {

        srand (time(NULL));

        if((rand() % 10) > 5) xwalkpos = 1;
        else xwalkpos = -1;

        if((rand() % 10) > 5) zwalkpos = 1;
        else zwalkpos = -1;


        switch(startdirection)
        {
            case 0:
                    srand (time(NULL));
                    nextx = ((2 + rand() % 6)* xwalkpos) + xAntPosition;
                    nextz = ((2 + rand() % 6)* zwalkpos) + zAntPosition;
                    break;
            case 1:
                    srand (time(NULL));
                    nextx = ((2 + rand() % 6)* xwalkpos) + xAntPosition;
                    nextz = ((2 + rand() % 6)* zwalkpos) + zAntPosition;
                    break;
            case 2:
                    srand (time(NULL));
                    nextx = ((2 + rand() % 6)* xwalkpos) + xAntPosition;
                    nextz = ((2 + rand() % 6)* zwalkpos) + zAntPosition;
                    break;
            case 3:
                    srand (time(NULL));
                    nextx = ((2 + rand() % 6)* xwalkpos) + xAntPosition;
                    nextz = ((2 + rand() % 6)* zwalkpos) + zAntPosition;
                    break;
        }

        if(nextx >= xworldsize-1)
        {
            nextx = xworldsize-2;
        }
        if(nextz >= zworldsize-1)
        {
            nextz = zworldsize-2;
        }
        if(nextx <= 1) nextx = 2;
        if(nextz <= 1) nextz = 2;

        cout<<"ant: x: "<<xAntPosition<<" z: "<<zAntPosition<<" target: x: "<<nextx<<" z: "<<nextz<<endl;
        if(worldvector[nextx][nextz].block)
        cout<<"Block:"<<endl;
        waytick = 0;
    }
    else
    {
        waytick++;
    }


    findWayTo(nextx, nextz);

//    switch(nextx)
//    {
//        case 0:
//                nextmove = 0;
//                break;
//        case 1:

//                nextmove = 1;
//                break;
//        case 2:

//                nextmove = 2;
//                break;
//        case 3:

//                nextmove = 3;
//                break;
//    }



    if (antViewVec[antViewRadius+1][antViewRadius].food > 0) //north is block
    {
        cout<<"food found north"<<endl;
        nextmove = 0;
    }
    if (antViewVec[antViewRadius-1][antViewRadius].food > 0) //south is block
    {
        cout<<"food found south"<<endl;
        nextmove = 2;
    }
    if (antViewVec[antViewRadius][antViewRadius-1].food > 0) //west is block
    {
        cout<<"food found west"<<endl;
        nextmove = 3;
    }
    if (antViewVec[antViewRadius][antViewRadius+1].food > 0) //east is block
    {
        cout<<"food found east"<<endl;
        nextmove = 1;
    }

}

void Ant::findWayTo(size_t xTo, size_t yTo)
{
    if (!followingPath)
    {
        pathfinder->updateMap(this);
        path = pathfinder->calculatePath(xAntPosition, zAntPosition, xTo, yTo);
//        cout << "weg: " << path << endl;
        followingPath = true;
    }
    else
    {
        pathfinder->updateMap(this);
        path = pathfinder->calculatePath(xAntPosition, zAntPosition, xTo, yTo);
//        cout << "länge: "<< path.length() << " weg neu: " << path << endl;
        static size_t i;
        if (path.length())
        {
            size_t direction =  path.at(0) - '0';
            if (direction <= 3)
            {
               nextmove = direction;
               i++;
            }
        }
        else
        {
            i = 0;
            followingPath = false;
        }
    }
}
