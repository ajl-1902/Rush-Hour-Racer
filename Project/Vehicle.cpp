#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle()
{
	posX = 0; posY = 0; vel = 0;
}

Vehicle::~Vehicle() {}

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