#include "ant.h"
#include <stdlib.h>

Ant::Ant():
    antViewRadius(2),
    done(false),
    status(SEARCH),
    waytick(1),
    nextmove(0),
    lastmove(0),
    followingPath(0),
    xFoodPos(0),
    yFoodPos(0),
    lastFoodValue(0),
    foodInSight(0),
    gesTime(0),
    foodbag(0),
    pathfinder(0),
    antLifeTime(lifeTime),
    antwarning(0)
{

    Square tmpSquare;
    tmpSquare.block = 9; //set to 'unseen by ant'
    std::vector <Square> tmpRow;

    for (size_t x = 0; x <= xworldsize; x++)
    {
        tmpRow.clear();
        for (size_t y = 0; y <= zworldsize; y++)
            tmpRow.push_back(tmpSquare);
        antMapVec.push_back(tmpRow);
    }

    for(int i = 0; i < antViewRadius; i++)
    {
        for(int b = 0; b < antViewRadius; b++)
        {
            tmpRow.push_back(tmpSquare);
        }
        antViewVec.push_back(tmpRow);
    }

}

int Ant::takeFood()
{
    if (foodbag < 10 && worldvector[xAntPosition][zAntPosition].food > 0)
    {
        while(foodbag < 10)
        {
            foodbag += 1;
            worldvector[xAntPosition][zAntPosition].food -= 1;
        }
        xFoodPos = xAntPosition;
        yFoodPos = zAntPosition;
        lastFoodValue = worldvector[xAntPosition][zAntPosition].food;
        return worldvector[xAntPosition][zAntPosition].food;
    }
    else
        return 0;
}

int Ant::bringFood()
{
    if (foodbag > 0)
    {
        *hillfood += foodbag;
        foodbag = 0;
        return 1;
    }
    else
        return 0;
}

int Ant::antmove(size_t a)	//move the ant
{
    if (a > 3) //check for valid movement
        return 1;

    movedirection = a;
    if (antalive)	//if the ant is alive
    {
        if (gesTime >= roundTime)
        {
            if (!pathfinder)
                pathfinder = new PathFind;
            oldxAntPosition = xAntPosition;
            oldzAntPosition = zAntPosition;

            switch (a)	//move
            {
                case 0:	//North
                        xAntPosition += 1;
                        break;

                case 1:	//East
                        zAntPosition += 1;
                        break;

                case 2:	//South
                        xAntPosition -= 1;
                        break;

                case 3:	//West
                        zAntPosition -= 1;
                        break;
            }

            antcollision();	//check if collision

            if (collision)
            {
                xAntPosition = oldxAntPosition;
                zAntPosition = oldzAntPosition;
            }
            xAntAnimPosition = oldxAntPosition;
            zAntAnimPosition = oldzAntPosition;

            gesTime = 0;

            return 1;
        }

        AntTimer.stop();
        difTime = AntTimer.getElapsedTimeInSec();
        if (difTime > 2) difTime = 0;	//remove first time
        else
        {
            gesTime += difTime/roundTime;
            antLifeTime -= difTime/roundTime;
        }

        if(antLifeTime <= 0)        antalive = 0;
        else if (antLifeTime <= 2)  antwarning = 1;
        else antwarning = 0;

        AntTimer.start();
    }
return 0;
}

void Ant::antcollision()
{
    collision = false;

    if (xAntPosition < 50 && zAntPosition < 50)
    if (xAntPosition > 0 && zAntPosition > 0)
    if (worldvector[xAntPosition][zAntPosition].block == 1)
    {
        collision = true;
    }

}

void Ant::setNextFood(int xwert, int zwert, int foodvalue)
{
    if(*nextfoodmanhattan == 0) *nextfoodmanhattan = 99;
    int newmanhattan = abs(*xhillorigin-xwert)+abs(*zhillorigin-zwert);
    cout<<"new manhattan: "<<newmanhattan<<" old manhattan: "<<*nextfoodmanhattan<<endl;

    if(foodvalue == 0)
    {
        cout<<"nextmanhattan = 99"<<endl;
        *nextfoodmanhattan = 99;
    }

    if(newmanhattan < *nextfoodmanhattan)
    {
        *nextfoodx = xwert;
        *nextfoodz = zwert;
        *nextfoodmanhattan = newmanhattan;
    }

}

void Ant::nearcheck()
{
    Square outSquare;
    outSquare.block = 1;
    std::vector<Square> tmpRow;
    antViewVec.clear();

    for (int x = -antViewRadius; x <= antViewRadius; x++)
    {
        for (int y = -antViewRadius; y <= antViewRadius; y++)
        {
            if ( (xAntPosition + x) < worldvector.size() && (zAntPosition + y) < worldvector[0].size() )
            {
                tmpRow.push_back(worldvector.at(xAntPosition + x).at(zAntPosition +y)); // live Ant view
                antMapVec.at(xAntPosition + x).at(zAntPosition + y) = worldvector.at(xAntPosition + x).at(zAntPosition + y); //update Ant map in memory
            }
            else
            {
//                cout << "debug: view out of map" << endl;
//                tmpRow.push_back(outSquare);
//                antMapVec.at(xAntPosition + x).at(zAntPosition + y) = outSquare;
            }
        }
        antViewVec.push_back(tmpRow);
        tmpRow.clear();
    }

}

void Ant::antspawn(int x, int z) //spawn a new ant
{
    if (antalive == 0) //if ant is not already alive
    {
        antalive = true;
        waytick = 5;
        foodbag = 0;
        gesTime = 0;
        yorigin = 0.0001;
        //*nextfoodmanhattan = 99;

        /* initialize random seed: */
        srand (time(NULL));

        /* generate secret number between 0 and 3: */
        startdirection = rand() % 3;
        cout<<"startdirection: "<<startdirection<<endl;
        //startdirection = 0;

        xAntPosition = x;
        zAntPosition = z;
        xAntAnimPosition = x;
        zAntAnimPosition = z;
        yAntPosition = 0.001;


        zorigin = zAntPosition;
        xorigin = xAntPosition;

        cout<<"Ant not alive. Ant created and spawned at: x="<<xAntPosition<<" z="<<zAntPosition<<endl;
    }
    else
        cout<<"ant already alive"<<endl;
}
