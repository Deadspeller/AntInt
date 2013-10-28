#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "vector"
#include "block.h"

extern vector < vector <worldstruct> > worldvector;

class LevelManager
{
public:
    LevelManager();
    bool loadFile();
    bool saveFile();
    void update();
    std::vector<Block*> blockVector();

private:
    std::vector<Block*> blockVec;
    Block* tempBlock;

    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
};

#endif // LEVELMANAGER_H
