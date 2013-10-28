#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "vector"
#include "block.h"

extern vector < vector <worldstruct> > worldvector;

class LevelManager
{
public:
    LevelManager();
    void LoadFile(const string File);
    void SaveFile();
    void Update();
    std::vector<Block> blockVector();

private:
    std::vector<Block> blockVec;

};

#endif // LEVELMANAGER_H
