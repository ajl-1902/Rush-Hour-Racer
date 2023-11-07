#pragma once
#include <vector>
#include "Vehicle.h"
using namespace std;

class Player :public Vehicle
{
private:
	static const int player_sizeX = 9;
	static const int player_sizeY = 15;

	char cell[player_sizeX][player_sizeY];
	int cell_pos[player_sizeX][player_sizeY][2];

	int model;

public:
	Player();
	Player(int);
	~Player();

	void setShape(int);
	char getShape(int, int);
	void setLocation();
	bool isHere(int, int);

	void editModel(int);
};