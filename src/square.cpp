#include "square.h"

Square::Square(int typeblock, float xposi, float zposi)
{
    switch (typeblock)
    {
        case 1: //block
                blockType = 1;
                break;

        case 2: //food
                food = 100;
                break;

        case 3: //ant

                break;
        default:
                break;
    }

}

Square::Square()
{}
