#include "objectcreator.h"

using namespace std;

void ObjectCreator::createBlock(size_t xwert, size_t zwert, int blocktype)
{
    if (xwert < worldvector.size() && zwert < worldvector.at(0).size()) // check if in vector
    {
        if (worldvector.at(xwert).at(zwert).block == 1  || worldvector.at(xwert).at(zwert).food > 0)
        {
            worldvector.at(xwert).at(zwert).block = 0;	//delete Block
            worldvector.at(xwert).at(zwert).food = 0;	//delete Food
            cout<<"delete block"<<endl;
        }
        else
        {
            if(blocktype == 1)
            {
                worldvector.at(xwert).at(zwert).block = blocktype;	// add Block
                cout<<"create block"<<endl;
            }

            if(blocktype == 2)
            {
                worldvector.at(xwert).at(zwert).food = 100;
                cout<<"create food"<<endl;
            }

        }
    }
}

void ObjectCreator::createHill(size_t x, size_t z)
{
    if (x < worldvector.size() && z < worldvector.at(0).size()) // check if in vector
    {
        worldvector.at(x).at(z).antHill = 1;
    }
}

