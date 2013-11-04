#include "square.h"

Square::Square(int typeblock, float xposi, float zposi):
    block(0),
    food(0),
    smell(0),
    antHill(0),
    ant(0)
{

    switch (typeblock)
    {
        case 1: //block
                block = 1;
                food = 0;
                break;

        case 2: //food
                food = 100;
                break;

        case 3: //ant

                break;
        case 4:
                block = 0;
                food = 0;
                break;
        default:
                block = 0;
                food = 0;
                antHill = 0;
                break;
    }

}

Square::Square()
{
    block = 0;
    food = 0;
    antHill = 0;

}
