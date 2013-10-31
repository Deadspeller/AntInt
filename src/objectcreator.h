
extern vector < vector <Square> > worldvector;
extern int xworldsize, zworldsize;


class ObjectCreator        //class for all classes, Wall-Blocks and Food-Blocks
{

public:
        
void createBlock(float xwert, float zwert, int blocktype)
{
	

                if(worldvector[xwert][zwert].blockType == 1  || worldvector[xwert][zwert].blockType == 2)
				{
                    worldvector[xwert][zwert].blockType = 0;	//delete Block
					cout<<"delete block"<<endl;		
				}				
				else
				{
                worldvector[xwert][zwert].blockType = blocktype;	// add Block
				cout<<"create block"<<endl;				
				}

	
}

void createHill(int x, int z)
{
	worldvector[x][z].blocktype = 4;
}

void createAnt(float xpos, float zpos)
{
        //worldvector[xpos][zpos];
}

                
}; //end Class
