#include <vector>
#include "Traffic.h"
using namespace std;

Traffic::Traffic(int diff) 
{
	this->setPos(1, 28);

	if (diff > 2) { this->setVel(2); }
	else this->setVel(1);

	this->setShape(1);
	this->setLocation();
}

Traffic::Traffic(int diff, int prev_lane)
{
	if (diff > 2) { this->setVel(2); }
	else this->setVel(1);

	srand(time(0));
	traffic_lane = prev_lane + (rand() % 3 - 1);
	//this->setVel(rand() % 2 + 1); Variable speeds?

	while (traffic_lane < 1 || traffic_lane > 3) 
	{
		traffic_lane = prev_lane + (rand() % 3 - 1);
	}

	switch (traffic_lane)
	{
	case 1:
		this->setPos(1, 5);
		break;

	case 2:
		this->setPos(1, 28);
		break;

	case 3:
		this->setPos(1, 52);
		break;
	}

	this->setShape(1);
	this->setLocation();
}

void Traffic::setShape(int mdl)
{
	for (int i = 0; i < traffic_sizeX; i++)
	{
		for (int j = 0; j < traffic_sizeY; j++)
		{
			cell[i][j] = ' ';
		}
	}

														  cell[0][4] = '_'; cell[0][5] = '_';	cell[0][6] = '_'; cell[0][7] = '_';	cell[0][8] = '_'; cell[0][9] = '_';	cell[0][10] = '_';
					  cell[1][2] = '_'; cell[1][3] = '|';																																   cell[1][11] = '|'; cell[1][12] = '_';
	cell[2][1] = '|'; cell[2][2] = '_'; cell[2][3] = '|';																																   cell[2][11] = '|'; cell[2][12] = '_'; cell[2][13] = '|';
										cell[3][3] = '|'; cell[3][4] = '-'; cell[3][5] = '-';	cell[3][6] = '-'; cell[3][7] = '-';	cell[3][8] = '-'; cell[3][9] = '-';	cell[3][10] = '-'; cell[3][11] = '|';
										cell[4][3] = '|';																																   cell[4][11] = '|';
										cell[5][3] = '|';																																   cell[5][11] = '|';
					  cell[6][2] = '_'; cell[6][3] = '|'; cell[6][4] = '-'; cell[6][5] = '-';	cell[6][6] = '-'; cell[6][7] = '-';	cell[6][8] = '-'; cell[6][9] = '-';	cell[6][10] = '-'; cell[6][11] = '|'; cell[6][12] = '_';
	cell[7][1] = '|'; cell[7][2] = '_'; cell[7][3] = '|';																																   cell[7][11] = '|'; cell[7][12] = '_'; cell[7][13] = '|';
										cell[8][3] = '|'; cell[8][4] = '_'; cell[8][5] = '_'; cell[8][6] = '_'; cell[8][7] = '_';	cell[8][8] = '_'; cell[8][9] = '_';	cell[8][10] = '_'; cell[8][11] = '|';
}

char Traffic::getShape(int X, int Y)
{
	for (int i = 0; i < traffic_sizeX; i++)
	{
		for (int j = 0; j < traffic_sizeY; j++)
		{
			if (cell_pos[i][j][0] == X && cell_pos[i][j][1] == Y)
				return cell[i][j];
		}
	}
}

void Traffic::setLocation()
{
	for (int i = 0; i < traffic_sizeX; i++)
	{
		for (int j = 0; j < traffic_sizeY; j++)
		{
			cell_pos[i][j][0] = this->getPos()[0] + i;
			cell_pos[i][j][1] = this->getPos()[1] + j;
		}
	}
}

bool Traffic::isHere(int X, int Y)
{
	for (int i = 0; i < traffic_sizeX; i++)
	{
		for (int j = 0; j < traffic_sizeY; j++)
		{
			if (cell_pos[i][j][0] == X && cell_pos[i][j][1] == Y) { return true; }
		}
	}
	return false;
}