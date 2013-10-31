#include "levelmanager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

LevelManager::LevelManager()
{
//    std::vector< std::vector<worldstruct> >::iterator row;
//    std::vector<worldstruct>::iterator col;
//    for(row = worldvector.begin(); row != worldvector.end(); row++)
//        for(col = row->begin(); col != row->end(); col++)
//        {
//            tempBlock = *new Block(col->blocktype, row - worldvector.begin(), col - row->begin());
//            blockVec.push_back(tempBlock);
//        }
}

void LevelManager::update()
{
    std::vector< std::vector<Square> >::iterator row;
    std::vector<Square>::iterator col;
    for(row = worldvector.begin(); row != worldvector.end(); row++)
        for(col = row->begin(); col != row->end(); col++)
        {
            tempBlock = *new Square(col->blockType, row - worldvector.begin(), col - row->begin());
//            cout << col->blocktype << "-";
            blockVec.push_back(tempBlock);
        }
}

std::vector<Square> LevelManager::blockVector()
{
    return blockVec;
}

std::vector<std::string> &LevelManager::split(const std::string &s, char delim, std::vector<std::string> &elems)
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
    std::ifstream mapFile;
    mapFile.open ("example.map");

    vector<string> lines;
    string str;
    while(getline(mapFile,str))
        lines.push_back(str);

    std::vector<string> number;
    std::vector<string>::iterator it, itStr;

    std::vector< std::vector<Square> >::iterator row;
    std::vector<Square>::iterator col;

    Square tmpSquare;
    std::vector<Square> tmpRow;

    row = worldvector.begin();
    col = row->begin();

    worldvector.clear();
    for (it = lines.begin() + 4; it != lines.end(); it++)
    {
        split(*it,',' , number);
        for (itStr = number.begin(); itStr != number.end(); itStr++)
        {
            std::stringstream out(*itStr);
            out >> tmpSquare.blockType;
//            cout << tmpSquare.blocktype << "+";
            tmpRow.push_back(tmpSquare);

//            out >> col->blocktype;
//            if (col != row->end()-1)
//                col++;
//            else if (row != worldvector.end()-1)
//            {
//                row++;
//                tmpRow.clear();
//            }
//            cout << *itStr << " + ";
        }
        worldvector.push_back(tmpRow);
        tmpRow.clear();
    }

//    for(row = worldvector.begin(); row != worldvector.end(); row++)
//    {
//        mapFile << endl;
//        for(col = row->begin(); col != row->end(); col++)
//            mapFile << col->blocktype << ",";
//    }
    mapFile.close();
}

bool LevelManager::saveFile()
{
    std::ofstream mapFile;
    mapFile.open ("example.map");
    mapFile << "Ant Intelligence Map File" << endl;
    mapFile << "v0.1" << endl;
    mapFile << "Map size: " << worldvector.size() << " X " << worldvector[0].size() << endl;
    std::vector< std::vector<Square> >::iterator row;
    std::vector<Square>::iterator col;
    for(row = worldvector.begin(); row != worldvector.end(); row++)
    {
        mapFile << endl;
        for(col = row->begin(); col != row->end(); col++)
            mapFile << col->blockType << ",";
    }
    mapFile.close();
}
