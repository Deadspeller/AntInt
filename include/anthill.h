	

class AntHill
{
	public:
	vector <Ant> antVec;
	Ant tempAnt;
	int xposition, zposition;

	void ki()
	{
		
		spawnAnt();

	}

	void spawnAnt()
	{
		antVec.push_back(tempAnt);
		antVec[antVec.size()-1].antspawn(xposition, zposition);
	}

	void spawnHill(int x, int z)
	{
		xposition = x;
		zposition = z;
	}
};
