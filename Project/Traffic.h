#pragma once
#include <vector>
#include "Vehicle.h"
using namespace std;

class Traffic :public Vehicle
{
private:
	static const int traffic_sizeX = 15;
	static const int traffic_sizeY = 9;

	char cell[traffic_sizeX][traffic_sizeY];
	int cell_pos[traffic_sizeX][traffic_sizeY][2];

public:
	Traffic();
	~Traffic();

	void setShape(int);
	char getShape(int, int);
	void setLocation();
};