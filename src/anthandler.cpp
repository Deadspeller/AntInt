#include "anthandler.h"

void AntHandler(string action)
{
    if (action == "move")	//move the existing Ants
    {
        for (int antcounter = 0; antcounter<maxants; antcounter++)
        {
            if (antarray[antcounter].antalive == 1)
            {
            antarray[antcounter].ki();
            }
        }
        for (int i=0; i<antHill1.antVec.size(); i++)
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
            antarray[antcounter].antspawn(xpos+1, zpos+1);
            cout<<"antcounter "<<antcounter<<endl;
            antcounter = maxants;

            }
        }

    }
}
