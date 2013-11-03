#include "ant.h"

int i = 0;
int lastmove = 0;
void Ant::ki()
{
        nearcheck();

            if (done)
            {
                cout<<"Vector"<<endl;
                for(int a = 0; a < antViewRows; a++)
                {
                    for(int b = 0; b <antViewColumns; b++)
                    {
                        cout<<antWorldVec[a][b].blockType<<" ";
                    }
                    cout<<endl;

                }
            }
            if(antworldarray[1][1] ==2)
            {
                takeFood();
            }

            switch (status)
            {
                case 1:
                        if (antworldarray[1][0]==1) //front is block
                        {
                            status = 3;
                        }
                        if (antworldarray[2][1]==2) //right is food
                        {
                            status = 3;
                        }
                        if (antworldarray[0][1]==2) //left is food
                        {
                            status = 4;
                        }
                        done = antmove(1);
                        break;

                case 2:
                        if (antworldarray[1][2]==1) //front is block
                        {
                            status = 4;
                        }
                        if (antworldarray[0][1]==2) //right is food
                        {
                            status = 4;
                        }
                        if (antworldarray[2][1]==2) //left is food
                        {
                            status = 3;
                        }
                        done = antmove(2);
                        break;

                case 3:
                        if (antworldarray[2][1]==1) //front is block
                        {
                            status = 2;
                        }
                        if (antworldarray[1][2]==2) //right is food
                        {
                            status = 2;
                        }
                        if (antworldarray[1][0]==2) //left is food
                        {
                            status = 1;
                        }
                        done = antmove(3);
                        break;

                case 4:
                        if (antworldarray[0][1]==1) //front is block
                        {
                            status = 1;
                        }
                        if (antworldarray[1][0]==2) //right is food
                        {
                            status = 1;
                        }
                        if (antworldarray[1][2]==2) //left is food
                        {
                            status = 2;
                        }
                        done = antmove(4);
                        break;

                default:
                            status = 1;
                            break;
            }


    switch (status)
    {
        case 1:
                done = antmove(1);
                break;

        case 2:
                done = antmove(2);
                break;

        case 3:
                done = antmove(3);
                break;

        case 4:
                done = antmove(4);
                break;

        default:
                    status = 1;
                    break;
    }
}

int Ant::takeFood()
{
    if(foodbag < 10 && worldvector[xAntPosition][zAntPosition].food > 0)
    {
        foodbag += 1;
        worldvector[xAntPosition][zAntPosition].food -= 1;
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
            cout<<"Ant Status: "<<a<<endl;
            oldxAntPosition = xAntPosition;
            oldzAntPosition = zAntPosition;

            switch (a)	//move
            {
                case 1:	//vor
                        xAntPosition += 1;
                        break;
                case 2:	//zurück
                        xAntPosition -= 1;
                        break;
                case 3:	//rechts
                        zAntPosition += 1;
                        break;
                case 4:	//links
                        zAntPosition -= 1;
                        break;
            }
            antcollision();	//check if collision

            if (collision)
            {
                cout<<"kollision"<<endl;
                xAntPosition = oldxAntPosition;
                zAntPosition = oldzAntPosition;
            }

            //worldvector[oldxAntPosition][oldzAntPosition].blockType = 0;
            //worldvector[xAntPosition][zAntPosition].blockType = 3;
            gesTime = 0;

            return 1;
        }

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
    if (worldvector[xAntPosition][zAntPosition].blockType == 1)
    {
        collision = true;
    }

}

void Ant::nearcheck()
{

    std::vector<Square> tmpRow;
    antWorldVec.clear();
    for (int r = floor(antViewRows/2); r >= 0-floor(antViewRows/2); r--)
    {
        for (int c = 0-floor(antViewColumns/2); c <= floor(antViewColumns/2); c++)
        {
            tmpRow.push_back(worldvector[xAntPosition+r][zAntPosition+c]);
        }
        antWorldVec.push_back(tmpRow);
        tmpRow.clear();
    }


    antworldarray[0][0] = worldvector[xAntPosition+1][zAntPosition-1].blockType;
    antworldarray[0][1] = worldvector[xAntPosition][zAntPosition-1].blockType;
    antworldarray[0][2] = worldvector[xAntPosition-1][zAntPosition-1].blockType;

    antworldarray[1][0] = worldvector[xAntPosition+1][zAntPosition].blockType;
    antworldarray[1][1] = worldvector[xAntPosition][zAntPosition].blockType;
    antworldarray[1][2] = worldvector[xAntPosition-1][zAntPosition].blockType;

    antworldarray[2][0] = worldvector[xAntPosition+1][zAntPosition+1].blockType;
    antworldarray[2][1] = worldvector[xAntPosition][zAntPosition+1].blockType;
    antworldarray[2][2] = worldvector[xAntPosition-1][zAntPosition+1].blockType;

}

void Ant::antspawn(int x, int z) //spawn a new ant
{

    if (antalive == 0) //if ant is not already alive
    {
        antalive = true;
        foodbag = 0;
        gesTime = 0;
        yorigin = 0.0001;

        //zAntPosition = round(zpos+1);
        //xAntPosition = round(xpos+1);
        xAntPosition = x;
        zAntPosition = z;
        yAntPosition = 0.001;

        zorigin = zAntPosition;
        xorigin = xAntPosition;

        antViewRows = 5;
        antViewColumns = 5;

        Square tmpSquare;
        vector <Square> tmprow;

        for(int i = 0; i < antViewRows; i++)
        {
            for(int b = 0; b < antViewColumns; b++)
            {
                tmprow.push_back(tmpSquare);
            }
            antWorldVec.push_back(tmprow);
        }


        //worldvector[xAntPosition][zAntPosition].blocktype = 3;
        cout<<"Zeiger pos: "<<xpos<<" "<<zpos<<endl;
        cout<<"Ant not alive. Ant created and spawned at: x="<<xAntPosition<<" z="<<zAntPosition<<endl;
    }
    else
        cout<<"ant already alive"<<endl;
}
