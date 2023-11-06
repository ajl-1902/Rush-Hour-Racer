#pragma once
#include <vector>
#include "Vehicle.h"
#include "Menu.h"
using namespace std;

class Player :public Vehicle
{
private:
	static const int player_sizeX = 14;
	static const int player_sizeY = 9;

	char cell[player_sizeX][player_sizeY];
	int cell_pos[player_sizeX][player_sizeY][2];

public:
	Player();
	~Player();

	void setShape(int mdl);
	char getShape();
};