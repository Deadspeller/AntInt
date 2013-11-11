#include "ant.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

void Ant::ki() //TODO: only call ki() once a round! (move drawing to levelDrawer)
{
    nearcheck();


    if (done)
    {
        if(sqrt(pow(abs(*xhillorigin-xAntPosition),2) + pow(abs(*zhillorigin-zAntPosition),2)) >= 13)
        {
            foodfound = 1; //too far away, go back
        }

        if(!foodfound)
        {
            switch(startdirection)
            {
                case 1:
                        if(waytick>=0 && waytick<=1)
                            status = 1;
                        else if(waytick>1 && waytick<6)
                            status = 3;
                        else if(waytick>=6 && waytick<=8)
                            status = 1;
                        else if(waytick>8 && waytick<18)
                            status = 4;
                        else if(waytick>=18 && waytick<=20)
                            status = 1;
                        else if(waytick>20 && waytick<30)
                            status = 3;
                        break;
                case 2:
                        if(waytick>=0 && waytick<=1)
                            status = 2;
                        else if(waytick>1 && waytick<6)
                            status = 4;
                        else if(waytick>=6 && waytick<=8)
                            status = 2;
                        else if(waytick>8 && waytick<18)
                            status = 3;
                        else if(waytick>=18 && waytick<=20)
                            status = 2;
                        else if(waytick>20 && waytick<30)
                            status = 4;
                        break;
                case 3:
                        if(waytick>=0 && waytick<=1)
                            status = 3;
                        else if(waytick>1 && waytick<6)
                            status = 2;
                        else if(waytick>=6 && waytick<=8)
                            status = 3;
                        else if(waytick>8 && waytick<18)
                            status = 1;
                        else if(waytick>=18 && waytick<=20)
                            status = 3;
                        else if(waytick>20 && waytick<30)
                            status = 2;
                        break;
                case 4:
                        if(waytick>=0 && waytick<=1)
                            status = 4;
                        else if(waytick>1 && waytick<6)
                            status = 1;
                        else if(waytick>=6 && waytick<=8)
                            status = 4;
                        else if(waytick>8 && waytick<18)
                            status = 2;
                        else if(waytick>=18 && waytick<=20)
                            status = 4;
                        else if(waytick>20 && waytick<30)
                            status = 1;
                        break;
            }

            if (antViewVec[floor(antViewRows/2)-1][floor(antViewColumns/2)].food > 0) //north is block
            {
                cout<<"food found"<<endl;
                status = 1;
            }
            if (antViewVec[floor(antViewRows/2)+1][floor(antViewColumns/2)].food > 0) //south is block
            {
                cout<<"food found"<<endl;
                status = 2;
            }
            if (antViewVec[floor(antViewRows/2)][floor(antViewColumns/2)-1].food > 0) //west is block
            {
                cout<<"food found"<<endl;
                status = 4;
            }
            if (antViewVec[floor(antViewRows/2)][floor(antViewColumns/2)+1].food > 0) //east is block
            {
                cout<<"food found"<<endl;
                status = 3;
            }

        }

            if(antViewVec[floor(antViewRows/2)][floor(antViewColumns/2)].food > 0)
            {
                takeFood();
                foodfound = 1;
            }

            if(foodfound)
            {

                if (!followingPath)
                {
                    pathfinder->updateMap(this);
                    path = pathfinder->calculatePath(xAntPosition,zAntPosition,*xhillorigin,*zhillorigin);
                    cout << "weg: " << path << endl;
                    followingPath = true;
                }

                if(followingPath)
                {
                    static size_t i;
                    if (i < path.length())
                    {
                        size_t direction =  path.at(i) - '0';
                        if (direction <= 3)
                            if (antmove(direction))
                                i++;
                        status = 99;
                    }
                    else
                        i=0;
                }


                if(*xhillorigin==xAntPosition && *zhillorigin==zAntPosition)
                {

                    status = 99;
                    if(bringFood())
                        cout<<"food zurückgebracht"<<endl;
                    foodfound = 0;
                    followingPath = false;
                    waytick = 0;
                }
                /*
                if(*xhillorigin<xAntPosition)    //hill is south
                {
                    if (antViewVec.at(1).at(2).block == 1) //south is block
                    {
                        if(*zhillorigin<zAntPosition)
                        {
                            status = 4;
                        }
                        else
                        {
                            status = 3;
                        }
                    }
                    else
                    if(lastmove != 1)
                    {
                        status = 2;
                    }
                }
                if(*xhillorigin>xAntPosition)    //hill is north
                {
                    if (antViewVec.at(1).at(0).block == 1) //north is block
                    {
                        if(*zhillorigin<zAntPosition)
                        {
                            status = 4;
                        }
                        else
                        {
                            status = 3;
                        }
                    }
                    else
                    if(lastmove != 2)
                    {
                        status = 1;
                    }
                }
                if(*zhillorigin<zAntPosition)    //hill is west
                {
                    if (antViewVec.at(0).at(1).block == 1) //west is block
                    {
                        if(*xhillorigin<xAntPosition)
                        {
                            status = 2;
                        }
                        else
                        {
                            status = 1;
                        }
                    }
                    else
                    if(lastmove != 3)
                    {
                        status = 4;
                    }

                }
                if(*zhillorigin>zAntPosition)    //hill is east
                {
                    if (antViewVec.at(2).at(1).block == 1) //east is block
                    {
                        if(*xhillorigin<xAntPosition)
                        {
                            status = 2;
                        }
                        else
                        {
                            status = 1;
                        }
                    }
                    else
                    if(lastmove != 4)
                    {
                        status = 3;
                    }
                }
                */
            }
            lastmove = status;
                if(!foodfound)
                {
                    if(waytick<29)waytick++;
                    else waytick = 6;
                }

    }


    switch (status)
    {
        case 1:
                done = antmove(0);
                break;

        case 2:
                done = antmove(2);
                break;

        case 3:
                done = antmove(1);
                break;

        case 4:
                done = antmove(3);
                break;

        default:
                    status = 1;
                    break;
    }


}
