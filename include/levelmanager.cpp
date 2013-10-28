#include "levelmanager.h"
#include <iostream>
#include <string>

LevelManager::LevelManager()
{
    std::vector< std::vector<worldstruct> >::iterator row;
    std::vector<worldstruct>::iterator col;
    for(row = worldvector.begin(); row != worldvector.end(); row++)
        for(col = row->begin(); col != row->end(); col++)
        {
            tempBlock = new Block(col->blocktype,0,0);
            blockVec.push_back(tempBlock);
        }
}

std::vector<Block*> LevelManager::blockVector()
{
    return blockVec;
}

void LevelManager::LoadFile(const string File)
{
//    FILE mapFile;

}
