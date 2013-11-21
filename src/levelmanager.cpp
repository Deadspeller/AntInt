#include "levelmanager.h"

//extern std::vector < std::vector <Square> > worldvector;

LevelManager::LevelManager()
{
//    std::vector< std::vector<worldstruct> >::iterator row;
//    std::vector<worldstruct>::iterator col;
//    for (row = worldvector.begin(); row != worldvector.end(); row++)
//        for (col l= row->begin(); col != row->end(); col++)
//        {
//            tempBlock = *new Block(col->blocktype, row - worldvector.begin(), col - row->begin());
//            blockVec.push_back(tempBlock);
//        }
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

    std::vector<std::string> squareProperties;
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
        squareProperties.clear();
        split(*it,',' , squareProperties);

        for (itStr = squareProperties.begin(); itStr != squareProperties.end(); itStr++)
        {
            char squareType = 0;
            int squareValue = 0;
            tmpSquare.reset();

            squareType = (*itStr)[0];
            if((*itStr).size() >= 2)
                istringstream ( ((*itStr).substr(1)) ) >> squareValue; //get digits; then convert to int

            switch (squareType)
            {
                case '0':
                break;

                case 'B':
                    tmpSquare.block = squareValue;
                break;

                case 'F':
                    tmpSquare.food = squareValue;
                break;

                case 'H':
                    tmpSquare.antHill = squareValue;
                break;

                default:
                    cout << "LoadLevel: ignoring Square (" << squareType << squareValue <<")" << endl;
            }

            tmpRow.push_back(tmpSquare);

        }
        worldvector.push_back(tmpRow);
        tmpRow.clear();
    }

    xworldsize = worldvector.size();
    zworldsize = worldvector.at(0).size();

    cout << "Level loaded - Size: " << xworldsize << " x " << zworldsize << endl;
    //setting up the "walls"
    for (size_t i = 0; i < zworldsize; i++)
        worldvector.at(i).at(0).block = 1;

    for (size_t i = 0; i < xworldsize; i++)
        worldvector.at(0).at(i).block = 1;

    for (size_t i = 0; i < zworldsize; i++)
        worldvector.at(i).at(xworldsize - 1).block = 1;

    for (size_t i = 0; i < xworldsize; i++)
        worldvector.at(zworldsize - 1).at(i).block = 1;

    mapFile.close();
    return true;
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
        {
            if (col->block > 0)
                mapFile << "B" << setfill('0') << setw(3) << col->block << ",";
            else if (col->food > 0)
                mapFile << "F" << setfill('0') << setw(3) << col->food << ",";
            else if (col->antHill > 0)
                mapFile << "H" << setfill('0') << setw(3) << col->antHill << ",";
            else
                mapFile << "0000" << ",";
        }
    }
    mapFile.close();
    return true;
}
