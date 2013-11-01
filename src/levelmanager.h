#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "square.h"

//extern std::vector < std::vector <Square> > worldvector;

class LevelManager
{
public:
    LevelManager();
    bool loadFile();
    bool saveFile();
    void update();
    std::vector<Square> blockVector();

private:
    std::vector<Square> blockVec;
    Square tempBlock;

    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
};

#endif // LEVELMANAGER_H
