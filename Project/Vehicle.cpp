#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle()
{
	posX = 0; posY = 0; vel = 0;
}

void Vehicle::setPos(int X, int Y)
{
	posX = X; posY = Y;
	this->setLocation();
}

vector<int> Vehicle::getPos()
{
	return pos = { posX,posY };
}

void Vehicle::setVel(int V)
{
	vel = V;
}

int Vehicle::getVel()
{
	return vel;
}

char Vehicle::getShapeDelta(int X, int Y, char curr_frame)
{
	if (this->isHere(X, Y))
	{
		return this->getShape(X, Y);
	}
	else return curr_frame;
}