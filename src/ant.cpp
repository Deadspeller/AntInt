#include "ant.h"


void Ant::ki()
{


    nearcheck();

        if (done)
        {
            if(!foodfound)
            {
                if(i>=0 && i<=1)
                    status = 1;
                else if(i>1 && i<6)
                    status = 4;
                else if(i>=6 && i<=8)
                    status = 1;
                else if(i>8 && i<18)
                    status = 3;
                else if(i>=18 && i<=20)
                    status = 1;
                else if(i>20 && i<30)
                    status = 4;
                else if(i==25)
                    status = 1;
                else if(i>25 && i<35)
                    status = 3;
                else if(i==35)
                    status = 1;
                else if(i>35 && i<45)
                    status = 4;

                if (antWorldVec[floor(antViewRows/2)-1][floor(antViewColumns/2)].food > 0) //north is block
                {
                    cout<<"north"<<endl;
                    status = 1;
                }
                if (antWorldVec[floor(antViewRows/2)+1][floor(antViewColumns/2)].food > 0) //south is block
                {
                    cout<<"south"<<endl;
                    status = 2;
                }
                if (antWorldVec[floor(antViewRows/2)][floor(antViewColumns/2)-1].food > 0) //west is block
                {
                    cout<<"west"<<endl;
                    status = 4;
                }
                if (antWorldVec[floor(antViewRows/2)][floor(antViewColumns/2)+1].food > 0) //east is block
                {
                    cout<<"east"<<endl;
                    status = 3;
                }

            }

                if(antWorldVec[floor(antViewRows/2)][floor(antViewColumns/2)].food > 0)
                {
                    takeFood();
                    foodfound = 1;
                }

                if(foodfound)
                {
                    if(*xhillorigin==xAntPosition && *zhillorigin==zAntPosition)
                    {
                        i = 0;
                        status = 1;
                        if(bringFood())
                            cout<<"food zurückgebracht"<<endl;
                        foodfound = 0;
                    }
                    if(*xhillorigin<xAntPosition)    //hill is south
                    {
                        if (antworldarray[1][2]==1) //south is block
                        {
                            if(*zhillorigin<zAntPosition)
                            {
                                status = 4;
                            }
                            else
                            {
                                status = 3;
                            }
                        }
                        else
                        if(lastmove != 1)
                        {
                            status = 2;
                        }
                    }
                    if(*xhillorigin>xAntPosition)    //hill is north
                    {
                        if (antworldarray[1][0]==1) //north is block
                        {
                            if(*zhillorigin<zAntPosition)
                            {
                                status = 4;
                            }
                            else
                            {
                                status = 3;
                            }
                        }
                        else
                        if(lastmove != 2)
                        {
                            status = 1;
                        }
                    }
                    if(*zhillorigin<zAntPosition)    //hill is west
                    {
                        if (antworldarray[0][1]==1) //west is block
                        {
                            if(*xhillorigin<xAntPosition)
                            {
                                status = 2;
                            }
                            else
                            {
                                status = 1;
                            }
                        }
                        else
                        if(lastmove != 3)
                        {
                            status = 4;
                        }

                    }
                    if(*zhillorigin>zAntPosition)    //hill is east
                    {
                        if (antworldarray[2][1]==1) //east is block
                        {
                            if(*xhillorigin<xAntPosition)
                            {
                                status = 2;
                            }
                            else
                            {
                                status = 1;
                            }
                        }
                        else
                        if(lastmove != 4)
                        {
                            status = 3;
                        }
                    }
                }
                lastmove = status;

            if(i<29)i++;
            else i = 6;

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

            //worldvector[oldxAntPosition][oldzAntPosition].block = 0;
            //worldvector[xAntPosition][zAntPosition].block = 3;
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
    if (worldvector[xAntPosition][zAntPosition].block == 1)
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


    antworldarray[0][0] = worldvector[xAntPosition+1][zAntPosition-1].block;
    antworldarray[0][1] = worldvector[xAntPosition][zAntPosition-1].block;
    antworldarray[0][2] = worldvector[xAntPosition-1][zAntPosition-1].block;

    antworldarray[1][0] = worldvector[xAntPosition+1][zAntPosition].block;
    antworldarray[1][1] = worldvector[xAntPosition][zAntPosition].block;
    antworldarray[1][2] = worldvector[xAntPosition-1][zAntPosition].block;

    antworldarray[2][0] = worldvector[xAntPosition+1][zAntPosition+1].block;
    antworldarray[2][1] = worldvector[xAntPosition][zAntPosition+1].block;
    antworldarray[2][2] = worldvector[xAntPosition-1][zAntPosition+1].block;

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
            antWorldVec.push_back(tmprow);
        }


        //worldvector[xAntPosition][zAntPosition].block = 3;
        cout<<"Zeiger pos: "<<xpos<<" "<<zpos<<endl;
        cout<<"Ant not alive. Ant created and spawned at: x="<<xAntPosition<<" z="<<zAntPosition<<endl;
    }
    else
        cout<<"ant already alive"<<endl;
}
