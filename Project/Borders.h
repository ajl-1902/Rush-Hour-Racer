#pragma once
#include "Vehicle.h"
using namespace std;

class Borders:public Vehicle
{
private:
	static const int ScreenSize = 72;

	char cell[ScreenSize];
	int cell_pos[ScreenSize][2];

	char border;

public:
	Borders(int, int, char);

	void setShape(int);
	char getShape(int, int);
	void setLocation();
	bool isHere(int, int);
};