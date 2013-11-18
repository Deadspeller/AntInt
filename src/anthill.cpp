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
    static int i;
    static float difTime;
    static float gesTime;
    static Timer moveTimer;

    moveTimer.stop();
    difTime = moveTimer.getElapsedTime();
    gesTime += difTime;

    if(gesTime >= roundTime/maxAnts)
    {
        antVec[i].ki();
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

void AntHill::setHill(size_t x, size_t z)
{
    if (x < worldvector.size() && z < worldvector.at(0).size())
    {
        xposition = x;
        zposition = z;
    }
}

AntHill::AntHill(int x, int z)
{
    setHill(x,z);
    food = 100;
}


