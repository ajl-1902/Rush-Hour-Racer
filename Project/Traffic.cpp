#include <vector>
#include "Traffic.h"
using namespace std;

Traffic::Traffic() {}
Traffic::~Traffic() {}

void Traffic::setShape(int mdl)
{
	for (int i = 0; i < traffic_sizeX; i++)
		for (int j = 0; j < traffic_sizeY; j++)
			cell[i][j] = ' ';

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