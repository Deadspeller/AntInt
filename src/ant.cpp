#include "ant.h"
#include <stdlib.h>

Ant::Ant():
    antViewRadius(1),
    done(false),
    status(SEARCH),
    waytick(1),
    nextmove(0),
    lastmove(0),
    followingPath(0),
    xFoodPos(0),
    yFoodpos(0),
    lastFoodValue(0),
    gesTime(0),
    foodbag(0),
    pathfinder(0)
{

    Square tmpSquare;
    tmpSquare.block = 9; //set to 'unseen by ant'
    std::vector <Square> tmpRow;

    for (size_t x = 0; x < xworldsize; x++)
    {
        tmpRow.clear();
        for (size_t y = 0; y < zworldsize; y++)
            tmpRow.push_back(tmpSquare);
        antMapVec.push_back(tmpRow);
    }

    for(int i = 0; i < antViewRadius; i++)
    {
        for(int b = 0; b < antViewRadius; b++)
        {
            tmpRow.push_back(tmpSquare);
        }
        antViewVec.push_back(tmpRow);
    }

}

int Ant::takeFood()
{
    if (foodbag < 10 && worldvector[xAntPosition][zAntPosition].food > 0)
    {
        while(foodbag < 10)
        {
            foodbag += 1;
            worldvector[xAntPosition][zAntPosition].food -= 1;
        }
        xFoodPos = xAntPosition;
        yFoodpos = zAntPosition;
        lastFoodValue = worldvector[xAntPosition][zAntPosition].food;
        return 1;
    }
    else
        return 0;
}

int Ant::bringFood()
{
    if (foodbag > 0)
    {
        *hillfood += foodbag;
        foodbag = 0;
        return 1;
    }
    else
        return 0;
}

int Ant::antmove(size_t a)	//move the ant
{
    if (a > 3) //check for valid movement
        return 1;

    movedirection = a;
    if (antalive)	//if the ant is alive
    {
        if (gesTime >= roundTime)
        {
            if (!pathfinder)
                pathfinder = new PathFind;
            oldxAntPosition = xAntPosition;
            oldzAntPosition = zAntPosition;

            switch (a)	//move
            {
                case 0:	//North
                        xAntPosition += 1;
                        break;

                case 1:	//East
                        zAntPosition += 1;
                        break;

                case 2:	//South
                        xAntPosition -= 1;
                        break;

                case 3:	//West
                        zAntPosition -= 1;
                        break;
            }

            antcollision();	//check if collision

            if (collision)
            {
                xAntPosition = oldxAntPosition;
                zAntPosition = oldzAntPosition;
            }

            //worldvector[oldxAntPosition][oldzAntPosition].block = 0;
            //worldvector[xAntPosition][zAntPosition].block = 3;
            gesTime = 0;

            return 1;
        }

        //TODO: move to leveldrawer/engine
        //draw the ant
        glPushMatrix();
        glTranslated(xAntPosition, yAntPosition, zAntPosition);

        switch (a)
        {
            case 0:	//vor
                    glRotatef(0,0.0,1.0,0.0);
                    break;
            case 1:	//zurück
                    glRotatef(180,0.0,1.0,0.0);
                    break;
            case 2:	//rechts
                    glRotatef(-90,0.0,1.0,0.0);
                    break;
            case 3:	//links
                    glRotatef(90,0.0,1.0,0.0);
                    break;
        }

        glScalef(0.5,0.5,0.5);
        glColor3f(1,0.1,0.1);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, tex_ant);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glColor4f(1,1,1,1); // If you do not set a color, the textured area will appear black.
        glBegin(GL_POLYGON); //ground
        glTexCoord2d(1,0);  glVertex3f(-1, 0.01, -1);
        glTexCoord2d(1,1);  glVertex3f(1, 0.01, -1);
        glTexCoord2d(0,1);  glVertex3f(1, 0.01, 1);
        glTexCoord2d(0,0);  glVertex3f(-1, 0.01, 1);
        glEnd();
        glDisable(GL_BLEND);
        glDisable(GL_TEXTURE_2D);
        glEnd();
        glPopMatrix();

        AntTimer.stop();
        difTime = AntTimer.getElapsedTimeInSec();
        if (difTime > 0.1) difTime = 0;	//remove first time
        gesTime += difTime;
        AntTimer.start();
    }
return 0;
}



void Ant::antcollision()
{
    collision = false;

    if (xAntPosition < 50 && zAntPosition < 50)
    if (xAntPosition > 0 && zAntPosition > 0)
    if (worldvector[xAntPosition][zAntPosition].block == 1)
    {
        collision = true;
    }

}

void Ant::nearcheck()
{
    Square outSquare;
    outSquare.block = 1;
    std::vector<Square> tmpRow;
    antViewVec.clear();

    for (int x = -antViewRadius; x <= antViewRadius; x++)
    {
        for (int y = -antViewRadius; y <= antViewRadius; y++)
        {
            if ( (xAntPosition + x) < worldvector.size() && (zAntPosition + y) < worldvector[0].size() )
            {
                tmpRow.push_back(worldvector.at(xAntPosition + x).at(zAntPosition +y));
                antMapVec.at(xAntPosition + x).at(zAntPosition + y) = worldvector[xAntPosition + x][zAntPosition + y];
            }
            else
            {
                cout << "debug: view out of map" << endl;
                tmpRow.push_back(outSquare);
                antMapVec.at(xAntPosition + x).at(zAntPosition + y) = outSquare;
            }
        }
        antViewVec.push_back(tmpRow);
        tmpRow.clear();
    }

    //test output of created map (spaw only one ant!)

//    std::vector< std::vector<Square> >::iterator row;
//    std::vector<Square>::iterator col;

//    for (row = antMapVec.begin(); row != antMapVec.end(); row++)
//    {
//        cout << std::endl;
//        for (col = row->begin(); col != row->end(); col++)
//            cout << col->block << ",";
//    }
//    cout << std::endl;
//    cout << std::endl;
}

void Ant::antspawn(int x, int z) //spawn a new ant
{

    if (antalive == 0) //if ant is not already alive
    {
        antalive = true;
        foodbag = 0;
        gesTime = 0;
        yorigin = 0.0001;

        /* initialize random seed: */
        srand (time(NULL));

        /* generate secret number between 0 and 3: */
        startdirection = rand() % 3;
        startdirection = 0;

        xAntPosition = x;
        zAntPosition = z;
        yAntPosition = 0.001;

        zorigin = zAntPosition;
        xorigin = xAntPosition;

        //worldvector[xAntPosition][zAntPosition].block = 3;
        cout<<"Zeiger pos: "<<xpos<<" "<<zpos<<endl;
        cout<<"Ant not alive. Ant created and spawned at: x="<<xAntPosition<<" z="<<zAntPosition<<endl;
    }
    else
        cout<<"ant already alive"<<endl;
}
