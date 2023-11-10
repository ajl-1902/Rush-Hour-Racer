#pragma once
#include <random>
#include "Vehicle.h"
using namespace std;

class Traffic :public Vehicle
{
private:
	static const int traffic_sizeX = 9;
	static const int traffic_sizeY = 15;

	char cell[traffic_sizeX][traffic_sizeY];
	int cell_pos[traffic_sizeX][traffic_sizeY][2];

	int traffic_lane;

public:
	Traffic(int);
	Traffic(int, int);

	void setShape(int);
	char getShape(int, int);
	void setLocation();
	bool isHere(int, int);

	int getTrafficLane();
};