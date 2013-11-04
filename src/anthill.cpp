#include "anthill.h"

void AntHill::ki()
{
    static float hillTime;
    static Timer hillTimer;
    hillTimer.stop();
    hillTime += hillTimer.getElapsedTime();


    if(hillTime >= 3 && antVec.size() < 1)
    {
        hillTime = 0;
        spawnAnt();
    }

    if(hillTime >= 1)
    {
        hillTime = 0;
        cout<<"HilFood: "<<food<<endl;
    }
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
        antVec[antVec.size()-1].anthillpointer = this;
        cout<<"Ants: "<<antVec.size()<<endl;
    }
    else
    {
        cout<<"Not enough food"<<endl;
    }

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
    food = 100;
}


