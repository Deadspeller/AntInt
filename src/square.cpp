#include "square.h"

Square::Square(int typeblock, float xposi, float zposi)
{
    switch (typeblock)
    {
        case 1: //block
                blockType = 1;
                food = 0;
                break;

        case 2: //food
                food = 100;
                break;

        case 3: //ant

                break;
        default:
                blockType = 0;
                food = 0;
                break;
    }

}

Square::Square()
{
    blockType = 0;
    food = 0;

}
