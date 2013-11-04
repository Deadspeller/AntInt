#include "objectcreator.h"

using namespace std;

void ObjectCreator::createBlock(float xwert, float zwert, int blocktype)
{
    if (worldvector[xwert][zwert].block == 1  || worldvector[xwert][zwert].block == 2)
    {
        worldvector[xwert][zwert].block = 0;	//delete Block
        cout<<"delete block"<<endl;
    }
    else
    {
    worldvector[xwert][zwert].block = blocktype;	// add Block
    if(blocktype = 2)worldvector[xwert][zwert].food = 100;
    cout<<"create block"<<endl;
    }
}

void ObjectCreator::createHill(int x, int z)
{
    worldvector[x][z].antHill = 1;
    cout<<"should be 1: "<<worldvector[x][z].antHill<<endl;
}

void ObjectCreator::createAnt(float xpos, float zpos)
{
//    worldvector[xpos][zpos];
}
