#include "anthandler.h"

extern float xlook, zlook;
extern float roundTime;

void AntHandler(string action)
{
    if (action == "move")	//move the existing Ants
    {
        for (int antcounter = 0; antcounter<maxants; antcounter++)
        {
            if (antarray[antcounter].antalive == 1 )
            {
            antarray[antcounter].ki();
            }
        }
        for (size_t i=0; i<antHill1.antVec.size(); i++)
        {
            antHill1.antVec[i].ki();
        }
    }

    if (action == "spawn")	//create a new Ant
    {
        for (int antcounter=0; antcounter<maxants; antcounter++)
        {
            if (antarray[antcounter].antalive == 0)
            {
            antarray[antcounter].antspawn(xlook, zlook);
            cout<<"antcounter "<<antcounter<<endl;
            antcounter = maxants;

            }
        }

    }
}
