#include "ant.h"
#include <stdlib.h>

Ant::Ant():
    antViewRows(3),
    antViewColumns(3),
    followingPath(0),
    gesTime(0),
    foodbag(0)
//    pathfinder()
{
    //initialization stuff here
    pathfinder = 0;
    Square tmp;
    tmp.block = 0; //set to 'unseen by ant'
    std::vector <Square> tmpRow;

    for (size_t x = 0; x < xworldsize; x++)
    {
        tmpRow.clear();
        for (size_t y = 0; y < zworldsize; y++)
            tmpRow.push_back(tmp);
        antMapVec.push_back(tmpRow);
    }

//    cout << "start: " << xAntPosition << ", " << zAntPosition << endl;
//    string path = pathfinder->calculatePath(xAntPosition,zAntPosition,1,1); // try to find a path to [1,1]
//    cout << path << endl;

}

int Ant::takeFood()
{
    if(foodbag < 10 && worldvector[xAntPosition][zAntPosition].food > 0)
    {
        while(foodbag < 10)
        {
            foodbag += 1;
            worldvector[xAntPosition][zAntPosition].food -= 1;
        }

        return 1;
    }
    else
        return 0;
}

int Ant::bringFood()
{
    if(foodbag > 0 && xAntPosition == *xhillorigin && zAntPosition == *zhillorigin)
    {
        *hillfood += foodbag;
        foodbag = 0;
        followingPath = false;
        return 1;
    }
    else
        return 0;
}

int Ant::antmove(int a)	//move the ant
{
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
//                cout<<"kollision"<<endl;
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
            case 1:	//vor
                    glRotatef(0,0.0,1.0,0.0);
                    break;
            case 2:	//zurück
                    glRotatef(180,0.0,1.0,0.0);
                    break;
            case 3:	//rechts
                    glRotatef(-90,0.0,1.0,0.0);
                    break;
            case 4:	//links
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

    std::vector<Square> tmpRow;
    antViewVec.clear();
    for (int r = floor(antViewRows/2); r >= 0-floor(antViewRows/2); r--)
    {
        for (int c = 0-floor(antViewColumns/2); c <= floor(antViewColumns/2); c++)
        {
            tmpRow.push_back(worldvector.at(xAntPosition+r).at(zAntPosition+c));
            antMapVec.at(xAntPosition + r).at(zAntPosition + c) = worldvector[xAntPosition+r][zAntPosition+c];
            //std::cout << antMapVec.at(xAntPosition + r).at(zAntPosition + c).block << " ";
        }
        //std::cout << std::endl;
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

        /* generate secret number between 1 and 4: */
        startdirection = rand() % 4 + 1;

        xAntPosition = x;
        zAntPosition = z;
        yAntPosition = 0.001;

        zorigin = zAntPosition;
        xorigin = xAntPosition;

        antViewRows = 3;
        antViewColumns = 3;
        i = 0;
        lastmove = 0;
        foodfound = 0;
        done = 1;
        status = 0;

        Square tmpSquare;
        vector <Square> tmprow;

        for(int i = 0; i < antViewRows; i++)
        {
            for(int b = 0; b < antViewColumns; b++)
            {
                tmprow.push_back(tmpSquare);
            }
            antViewVec.push_back(tmprow);
        }

        //worldvector[xAntPosition][zAntPosition].block = 3;
        cout<<"Zeiger pos: "<<xpos<<" "<<zpos<<endl;
        cout<<"Ant not alive. Ant created and spawned at: x="<<xAntPosition<<" z="<<zAntPosition<<endl;
    }
    else
        cout<<"ant already alive"<<endl;
}
