#pragma once
#include <random>
#include "Vehicle.h"
using namespace std;

class Traffic :public Vehicle
{
private:
	// Define outer boundaries for traffic entity
	static const int traffic_sizeX = 9;
	static const int traffic_sizeY = 15;

	char cell[traffic_sizeX][traffic_sizeY]; // Stores character located at a certain point
	int cell_pos[traffic_sizeX][traffic_sizeY][2]; // Stores the physical location of the characters above

	int traffic_lane;
	int count;

public:
	Traffic(int); // Intital traffic entity
	Traffic(int, int); // Subsequent traffic entities

	void setShape(int);
	char getShape(int, int);
	void setLocation();
	bool isHere(int, int);

	int getTrafficLane();
};