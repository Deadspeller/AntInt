#include "anthill.h"

void AntHill::ki()
{
    static float hillTime;
    static Timer hillTimer;
    hillTimer.stop();
    hillTime += hillTimer.getElapsedTime();


    if(hillTime >= 1 && antVec.size() < maxAnts)
    {
        hillTime = 0;
        spawnAnt();
    }

    moveAnts();

    hillTimer.start();
}

void AntHill::spawnAnt()
{
    if(food > 0)
    {
        food -= 5;
        antVec.push_back(tempAnt);
        antVec[antVec.size()-1].antspawn(xposition, zposition);
        antVec[antVec.size()-1].xhillorigin = &xposition;
        antVec[antVec.size()-1].zhillorigin = &zposition;
        antVec[antVec.size()-1].hillfood = &food;
        antVec[antVec.size()-1].nextfoodx = &nextfoodx;
        antVec[antVec.size()-1].nextfoodz = &nextfoodz;
        antVec[antVec.size()-1].nextfoodmanhattan = &nextfoodmanhattan;
        antVec[antVec.size()-1].anthillpointer = this;
        cout<<"Ants: "<<antVec.size()<<endl;
    }
    else
    {
        cout<<"Not enough food"<<endl;
    }
}



void AntHill::moveAnts()
{
    static float difTime;
    static float gesTime;
    static Timer moveTimer;

    static size_t i;

    moveTimer.stop();
    difTime = moveTimer.getElapsedTime();
    gesTime += difTime;

    if (gesTime >= roundTime/maxAnts)
    {
        if (antVec.size() > 0)
        {
            if (antVec[i].antalive == 0)
            {
                std::vector<Ant>::iterator iter;
                iter = antVec.begin() + i;
                antVec.erase(iter);
            }
            else
            {
                antVec[i].ki();
            }
        }
        i++;
        gesTime = 0;
        difTime = 0;
    }
    if(i >= antVec.size())
    {
        i=0;
    }

//    for (size_t i=0; i < antVec.size(); i++)
//    {
//        //antVec[i].ki();
//    }

    moveTimer.start();
}

Timer AnimationTimer;

void AntHill::antanimation()
{
    float difTime;

    AnimationTimer.stop();
    difTime = AnimationTimer.getElapsedTimeInSec();
    if(difTime > 1)difTime = 0;

    for (size_t i=0; i < antVec.size(); i++)
    {
        if(antVec[i].xAntAnimPosition <= antVec[i].xAntPosition)
        {
            antVec[i].xAntAnimPosition += difTime*AntSpeed/roundTime;
            if(antVec[i].xAntAnimPosition >= antVec[i].xAntPosition)
            {
                antVec[i].xAntAnimPosition = antVec[i].xAntPosition;
            }

        }
        else if(antVec[i].xAntAnimPosition > antVec[i].xAntPosition)
        {
            antVec[i].xAntAnimPosition -= difTime*AntSpeed/roundTime;
            if(antVec[i].xAntAnimPosition <= antVec[i].xAntPosition)
            {
                antVec[i].xAntAnimPosition = antVec[i].xAntPosition;
            }

        }

        if(antVec[i].zAntAnimPosition <= antVec[i].zAntPosition)
        {
            antVec[i].zAntAnimPosition += difTime*AntSpeed/roundTime;
            if(antVec[i].zAntAnimPosition >= antVec[i].zAntPosition)
            {
                antVec[i].zAntAnimPosition = antVec[i].zAntPosition;
            }

        }
        else if(antVec[i].zAntAnimPosition > antVec[i].zAntPosition)
        {
            antVec[i].zAntAnimPosition -= difTime*AntSpeed/roundTime;
            if(antVec[i].zAntAnimPosition <= antVec[i].zAntPosition)
            {
                antVec[i].zAntAnimPosition = antVec[i].zAntPosition;
            }

        }

    }
    AnimationTimer.start();
}

void AntHill::setHill(size_t x, size_t z)
{
    if (x < worldvector.size() && z < worldvector.at(x).size())
    {
        worldvector[xposition][zposition].antHill = 0;
        xposition = x;
        zposition = z;
        worldvector[xposition][zposition].antHill = 1;
    }
}

AntHill::AntHill(int x, int z)
{
    setHill(x,z);
    food = 100;
}


