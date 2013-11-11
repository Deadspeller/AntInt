#include "ant.h"
#include "antki.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

bool done = false;
int status = 0;
int nextmove = 0;
bool followingPath = 0;



void Ant::ki() //TODO: only call ki() once a round! (move drawing to levelDrawer)
{

    if(done)    //ant was moved, now calculate new.
    {
        switch (status)
        {
            case 0:     //suche futter
                    searchfood();
                    if(antViewVec[floor(antViewRows/2)][floor(antViewColumns/2)].food >= 1 )
                    {
                        status = 1;
                    }
                    break;

            case 1:     //futter aufnehmen
                    takeFood();
                    break;

            case 2:     //A* zum Bau

                    break;

            case 3:     //Futter ablegen

                    break;

            case 4:     //A* zum Futter

                    break;

            case 5:     //Futter ablegen
                    bringFood();
                    break;

            default:
                    status = 0;
                    break;
        }
    }



    switch (nextmove)
    {
        case 0:     //move north
                done = antmove(0);
                break;

        case 1:     //move east
                done = antmove(1);
                break;

        case 2:     //move south
                done = antmove(2);
                break;

        case 3:     //move west
                done = antmove(3);
                break;

        default:
                nextmove = 0;
                break;
    }

}

void searchfood()
{

    nextmove = 1;
}
