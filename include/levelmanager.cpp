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
            blockVec.push_back( new Block(col->blocktype) );
            std::cout << col->blocktype;
        }
}

std::vector<Block> LevelManager::blockVector()
{
    return blockVec;
}

void LevelManager::LoadFile(const string File)
{
//    FILE mapFile;

}
