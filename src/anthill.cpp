#include "anthill.h"

void AntHill::ki()
{
    static float hillTime;
    static Timer hillTimer;
    hillTimer.stop();
    hillTime += hillTimer.getElapsedTime();


    if(hillTime >= 3 && antVec.size() < 5)
    {
        hillTime = 0;
        spawnAnt();
    }


    hillTimer.start();
}

void AntHill::spawnAnt()
{
    antVec.push_back(tempAnt);
    antVec[antVec.size()-1].antspawn(xposition, zposition);
    cout<<"Ants: "<<antVec.size()<<endl;
}

void AntHill::setHill(int x, int z)
{
    xposition = x;
    zposition = z;
}

AntHill::AntHill(float x, float z)
{
    xposition = x;
    zposition = z;

}


