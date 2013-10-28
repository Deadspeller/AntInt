#include "levelmanager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

LevelManager::LevelManager()
{
    update();
}

void LevelManager::update()
{
    blockVec.clear();
    std::vector< std::vector<worldstruct> >::iterator row;
    std::vector<worldstruct>::iterator col;
    for(row = worldvector.begin(); row != worldvector.end(); row++)
        for(col = row->begin(); col != row->end(); col++)
        {
            tempBlock = new Block(col->blocktype, row - worldvector.begin(), col - row->begin());
            blockVec.push_back(tempBlock);
        }
}

std::vector<Block*> LevelManager::blockVector()
{
    return blockVec;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

bool LevelManager::loadFile()
{
//    std::ifstream mapFile;
//    mapFile.open ("example.map");

//    vector<string> lines;
//    string str;
//    while(getline(mapFile,str))
//        lines.push_back(str);

//    std::vector<string> number;
//    std::vector<string>::iterator it, itStr;
//    for (it = lines.begin() + 4; it != lines.end(); it++)
//    {
//        split(*it,',' , number);
//        for (itStr = number.begin(); itStr != number.end(); itStr++)
//            cout << *itStr << " + ";
//        cout << endl;
//    }
////    std::vector< std::vector<worldstruct> >::iterator row;
////    std::vector<worldstruct>::iterator col;
////    for(row = worldvector.begin(); row != worldvector.end(); row++)
////    {
////        mapFile << endl;
////        for(col = row->begin(); col != row->end(); col++)
////            mapFile << col->blocktype << ",";
////    }
//    mapFile.close();
}

bool LevelManager::saveFile()
{
    std::ofstream mapFile;
    mapFile.open ("example.map");
    mapFile << "Ant Intelligence Map File" << endl;
    mapFile << "v0.1" << endl;
    mapFile << "Map size: " << worldvector.size() << " X " << worldvector[0].size() << endl;
    std::vector< std::vector<worldstruct> >::iterator row;
    std::vector<worldstruct>::iterator col;
    for(row = worldvector.begin(); row != worldvector.end(); row++)
    {
        mapFile << endl;
        for(col = row->begin(); col != row->end(); col++)
            mapFile << col->blocktype << ",";
    }
    mapFile.close();
}
