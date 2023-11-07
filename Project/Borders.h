#pragma once
#include "Vehicle.h"
using namespace std;

class Borders:public Vehicle
{
private:
	static const int ScreenSize = 72;
	char cell[ScreenSize][ScreenSize];
	int cell_pos[ScreenSize][ScreenSize][2];
public:
	Borders();
	//~Borders();

	void setShape(int);
	char getShape(int, int);
	void setLocation();
	bool isHere(int, int);
};