#include "levelmanager.h"

//extern std::vector < std::vector <Square> > worldvector;

LevelManager::LevelManager()
{
//    std::vector< std::vector<worldstruct> >::iterator row;
//    std::vector<worldstruct>::iterator col;
//    for (row = worldvector.begin(); row != worldvector.end(); row++)
//        for (col = row->begin(); col != row->end(); col++)
//        {
//            tempBlock = *new Block(col->blocktype, row - worldvector.begin(), col - row->begin());
//            blockVec.push_back(tempBlock);
//        }
}

void LevelManager::update()
{
    std::vector< std::vector<Square> >::iterator row;
    std::vector<Square>::iterator col;
    for (row = worldvector.begin(); row != worldvector.end(); row++)
        for (col = row->begin(); col != row->end(); col++)
        {
            tempBlock = *new Square(col->block, row - worldvector.begin(), col - row->begin());
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
    if (!mapFile)
        return 0;

    std::vector<std::string> lines;
    std::string str;
    while (getline(mapFile,str))
        lines.push_back(str);

    std::vector<std::string> number;
    std::vector<std::string>::iterator it, itStr;

    std::vector< std::vector<Square> >::iterator row;
    std::vector<Square>::iterator col;

    Square tmpSquare;
    std::vector<Square> tmpRow;

    row = worldvector.begin();
    col = row->begin();

    worldvector.clear();
    for (it = lines.begin() + 4; it != lines.end(); it++)
    {
        number.clear();
        split(*it,',' , number);

        for (itStr = number.begin(); itStr != number.end(); itStr++)
        {
            istringstream (*itStr) >> tmpSquare.block; // convert to int and assign to blocktype
            tmpRow.push_back(tmpSquare);
            if(tmpSquare.block == 2)    //set food to 100
            {
                tmpSquare.food = 100;
            }
        }
        worldvector.push_back(tmpRow);
        tmpRow.clear();
    }

    mapFile.close();
}

bool LevelManager::saveFile()
{
    std::ofstream mapFile;
    mapFile.open ("example.map");
    mapFile << "Ant Intelligence Map File" << std::endl;
    mapFile << "v0.1" << std::endl;
    mapFile << "Map size: " << worldvector.size() << " X " << worldvector[0].size() << std::endl;

    std::vector< std::vector<Square> >::iterator row;
    std::vector<Square>::iterator col;

    for (row = worldvector.begin(); row != worldvector.end(); row++)
    {
        mapFile << std::endl;
        for (col = row->begin(); col != row->end(); col++)
            mapFile << col->block << ",";
    }
    mapFile.close();
}
