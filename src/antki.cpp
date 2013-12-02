#include "ant.h"
#include "pathfind.h"
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
                    foodleft = takeFood();

                    if (foodleft || foodbag > 0)
                    {
                          status = GOHOME;
                    }
                    else
                    {
                        *nextfoodmanhattan = 99;
                        status = SEARCH;
                    }

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
                        setNextFood(xFoodPos, yFoodPos, foodleft);
                        status = GOFOOD;
                        waytick = 0;
                    }
                    break;

            case GOFOOD:     //A* zum Futter
                    if(*nextfoodmanhattan<99)
                    {
                        findWayTo(*nextfoodx, *nextfoodz);
                    }
                    else
                        status = SEARCH;

                    //findWayTo(xFoodPos, yFoodpos);
                    if(xAntPosition == *nextfoodx && zAntPosition == *nextfoodz)
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

    if (!foodInSight)
    {
        if (waytick >= 4 || (xAntPosition == nextx && zAntPosition == nextz))
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
                        nextx = ((2 + rand() % 6)* xwalkpos+1) + xAntPosition;
                        nextz = ((2 + rand() % 6)* zwalkpos+1) + zAntPosition;
                        break;
                case 1:
                        srand (time(NULL));
                        nextx = ((2 + rand() % 6)* xwalkpos+1) + xAntPosition;
                        nextz = ((2 + rand() % 6)* zwalkpos+1) + zAntPosition;
                        break;
                case 2:
                        srand (time(NULL));
                        nextx = ((2 + rand() % 6)* xwalkpos-1) + xAntPosition;
                        nextz = ((2 + rand() % 6)* zwalkpos-1) + zAntPosition;
                        break;
                case 3:
                        srand (time(NULL));
                        nextx = ((2 + rand() % 6)* xwalkpos-1) + xAntPosition;
                        nextz = ((2 + rand() % 6)* zwalkpos-1) + zAntPosition;
                        break;
            }

            if (nextx >= xworldsize-1)
            {
                nextx = xworldsize-2;
            }
            if (nextz >= zworldsize-1)
            {
                nextz = zworldsize-2;
            }
            if (nextx <= 1) nextx = 2;
            if (nextz <= 1) nextz = 2;

            if(antMapVec[nextx][nextz].block==1)
            {
                nextx = xAntPosition;
                nextz = zAntPosition;
            }
            waytick = 0;
        }
        else
        {
            waytick++;
        }

        findWayTo(nextx, nextz);

        //detect Food in sight
        for (size_t x = 0; x < antViewVec.size(); x++)
        {
            for (size_t y = 0; y < antViewVec[x].size(); y++)
            {
                if (antViewVec[x][y].food)
                {
                    xFoodPos = xAntPosition + x - antViewRadius; //calculate absolute food position
                    yFoodPos = zAntPosition + y - antViewRadius;
                    cout << "seeing food at " << xFoodPos << "," << yFoodPos << endl;
                    foodInSight = true;
                }
            }
        }
    }
    else //food in sight
    {
        if (findWayTo(xFoodPos, yFoodPos)) // arrived at food
            foodInSight = false;
    }


//    if (antViewVec[antViewRadius+1][antViewRadius].food > 0) //north is block
//    {
//        nextmove = 0;
//    }
//    if (antViewVec[antViewRadius-1][antViewRadius].food > 0) //south is block
//    {
//        nextmove = 2;
//    }
//    if (antViewVec[antViewRadius][antViewRadius-1].food > 0) //west is block
//    {
//        nextmove = 3;
//    }
//    if (antViewVec[antViewRadius][antViewRadius+1].food > 0) //east is block
//    {
//        nextmove = 1;
//    }
}

bool Ant::findWayTo(size_t xTo, size_t yTo)
{
    if (!followingPath)
    {
        pathfinder->updateMap(this);
        path = pathfinder->calculatePath(xAntPosition, zAntPosition, xTo, yTo);
//        cout << "weg: " << path << endl;
        followingPath = true;
        return false;
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
            return false;
        }
        else
        {
            i = 0;
            nextmove = 9;
            followingPath = false;
            return true;
        }
    }
}
