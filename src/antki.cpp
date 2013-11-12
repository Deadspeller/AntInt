#include "ant.h"
#include "pathfind.h"
#include "antki.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

extern int startdirection,antViewRows, antViewColumns;

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

void Ant::searchfood()
{
    if(waytick<29)
        waytick++;
    else
        waytick = 6;

    switch(startdirection)
    {
        case 0:
                if(waytick>=0 && waytick<=1)
                    nextmove = 0;
                else if(waytick>1 && waytick<6)
                    nextmove = 1;
                else if(waytick>=6 && waytick<=8)
                    nextmove = 0;
                else if(waytick>8 && waytick<18)
                    nextmove = 3;
                else if(waytick>=18 && waytick<=20)
                    nextmove = 0;
                else if(waytick>20 && waytick<30)
                    nextmove = 1;
                break;
        case 1:
                if(waytick>=0 && waytick<=1)
                    nextmove = 2;
                else if(waytick>1 && waytick<6)
                    nextmove = 3;
                else if(waytick>=6 && waytick<=8)
                    nextmove = 2;
                else if(waytick>8 && waytick<18)
                    nextmove = 1;
                else if(waytick>=18 && waytick<=20)
                    nextmove = 2;
                else if(waytick>20 && waytick<30)
                    nextmove = 3;
                break;
        case 2:
                if(waytick>=0 && waytick<=1)
                    nextmove = 0;
                else if(waytick>1 && waytick<6)
                    nextmove = 2;
                else if(waytick>=6 && waytick<=8)
                    nextmove = 3;
                else if(waytick>8 && waytick<18)
                    nextmove = 0;
                else if(waytick>=18 && waytick<=20)
                    nextmove = 1;
                else if(waytick>20 && waytick<30)
                    nextmove = 2;
                break;
        case 3:
                if(waytick>=0 && waytick<=1)
                    nextmove = 3;
                else if(waytick>1 && waytick<6)
                    nextmove = 0;
                else if(waytick>=6 && waytick<=8)
                    nextmove = 3;
                else if(waytick>8 && waytick<18)
                    nextmove = 2;
                else if(waytick>=18 && waytick<=20)
                    nextmove = 3;
                else if(waytick>20 && waytick<30)
                    nextmove = 0;
                break;
    }



    if (antViewVec[floor(antViewRows/2)-1][floor(antViewColumns/2)].food > 0) //north is block
    {
        cout<<"food found north"<<endl;
        nextmove = 0;
    }
    if (antViewVec[floor(antViewRows/2)+1][floor(antViewColumns/2)].food > 0) //south is block
    {
        cout<<"food found south"<<endl;
        nextmove = 2;
    }
    if (antViewVec[floor(antViewRows/2)][floor(antViewColumns/2)-1].food > 0) //west is block
    {
        cout<<"food found west"<<endl;
        nextmove = 3;
    }
    if (antViewVec[floor(antViewRows/2)][floor(antViewColumns/2)+1].food > 0) //east is block
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
