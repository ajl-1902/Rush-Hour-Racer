#pragma once
#include "Vehicle.h"
using namespace std;

// Borders was originally a standalone class, but making use of functions derived from Vehicle made outputting of game window significantly more efficient
// (Hence why the names "Borders" and "Vehicle" do not explicitly relate to each other)
class Borders:public Vehicle
{
private:
	static const int ScreenSize = 72;

	char cell[ScreenSize]; // Stores character located at a certain point
	int cell_pos[ScreenSize][2]; // Stores the physical location of the characters above

	char border;

public:
	Borders(int, int, char);

	void setShape(int);
	char getShape(int, int);
	void setLocation();
	bool isHere(int, int);
};