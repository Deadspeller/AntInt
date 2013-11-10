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
                        if(i>=0 && i<=1)
                            status = 1;
                        else if(i>1 && i<6)
                            status = 4;
                        else if(i>=6 && i<=8)
                            status = 1;
                        else if(i>8 && i<18)
                            status = 3;
                        else if(i>=18 && i<=20)
                            status = 1;
                        else if(i>20 && i<30)
                            status = 4;
                        break;
                case 2:
                        if(i>=0 && i<=1)
                            status = 2;
                        else if(i>1 && i<6)
                            status = 4;
                        else if(i>=6 && i<=8)
                            status = 2;
                        else if(i>8 && i<18)
                            status = 3;
                        else if(i>=18 && i<=20)
                            status = 2;
                        else if(i>20 && i<30)
                            status = 4;
                        break;
                case 3:
                        if(i>=0 && i<=1)
                            status = 3;
                        else if(i>1 && i<6)
                            status = 2;
                        else if(i>=6 && i<=8)
                            status = 3;
                        else if(i>8 && i<18)
                            status = 1;
                        else if(i>=18 && i<=20)
                            status = 3;
                        else if(i>20 && i<30)
                            status = 2;
                        break;
                case 4:
                        if(i>=0 && i<=1)
                            status = 4;
                        else if(i>1 && i<6)
                            status = 1;
                        else if(i>=6 && i<=8)
                            status = 4;
                        else if(i>8 && i<18)
                            status = 2;
                        else if(i>=18 && i<=20)
                            status = 4;
                        else if(i>20 && i<30)
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
                    pathfinder->updateMap();
                    path = pathfinder->calculatePath(xAntPosition,zAntPosition,*xhillorigin,*zhillorigin);
                    cout << "weg: " << path << endl;
                    followingPath = true;
                }

                static size_t i;
                if (i < path.length())
                {
                    size_t direction =  path.at(i) - '0';
                    if (direction <= 3)
                        if (antmove(direction))
                            i++;
                    status = 99;
                }


                if(*xhillorigin==xAntPosition && *zhillorigin==zAntPosition)
                {
                    i = 0;
                    status = 1;
                    if(bringFood())
                        cout<<"food zurückgebracht"<<endl;
                    foodfound = 0;
                    followingPath = false;
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

        if(i<29)i++;
        else i = 6;

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
