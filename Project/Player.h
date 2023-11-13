#pragma once
#include "Vehicle.h"
using namespace std;

class Player :public Vehicle
{
private:
	// Defines outer boundaries for player car
	static const int player_sizeX = 9;
	static const int player_sizeY = 15;

	char cell[player_sizeX][player_sizeY]; // Stores character located at a certain point
	int cell_pos[player_sizeX][player_sizeY][2]; // Stores the physical location of the characters above

	int model;

public:
	Player();

	void setShape(int);
	char getShape(int, int);
	void setLocation();
	bool isHere(int, int);

	void editModel(int);
};