#include "objectcreator.h"

using namespace std;

void ObjectCreator::createBlock(float xwert, float zwert, int blocktype)
{
    if (worldvector[xwert][zwert].blockType == 1  || worldvector[xwert][zwert].blockType == 2)
    {
        worldvector[xwert][zwert].blockType = 0;	//delete Block
        cout<<"delete block"<<endl;
    }
    else
    {
    worldvector[xwert][zwert].blockType = blocktype;	// add Block
    cout<<"create block"<<endl;
    }
}

void ObjectCreator::createHill(int x, int z)
{
    worldvector[x][z].blockType = 4;
}

void ObjectCreator::createAnt(float xpos, float zpos)
{
//    worldvector[xpos][zpos];
}
