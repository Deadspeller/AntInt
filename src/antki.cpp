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

void Ant::searchfood()
{

    if(waytick>=3 || (xAntPosition == nextx && zAntPosition == nextz))
    {
        /* initialize random seed: */
        srand (time(NULL));
        /* generate secret number between -3 and 3: */

        switch(startdirection)
        {
            case 0:
                    nextx = -6 + rand() % 12 + xAntPosition;
                    cout<<" ";
                    nextz = -6 + rand() % 12 + zAntPosition;
                    break;
            case 1:
                    nextx = -6 + rand() % 12 + xAntPosition;
                    nextz = -6 + rand() % 12 + zAntPosition;
                    break;
            case 2:
                    nextx = -6 + rand() % 12 + xAntPosition;
                    nextz = -6 + rand() % 12 + zAntPosition;
                    break;
            case 3:
                    nextx = -6 + rand() % 12 + xAntPosition;
                    nextz = -6 + rand() % 12 + zAntPosition;
                    break;
        }

        if(nextx > xworldsize) nextx = xworldsize-1;
        if(nextz > zworldsize) nextz = zworldsize-1;


        cout<<"ant: x: "<<xAntPosition<<" z: "<<zAntPosition<<" target: x: "<<nextx<<" z: "<<nextz<<endl;
        waytick = 0;
    }
    else
    {
        cout<<"tick"<<endl;
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
