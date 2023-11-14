#include "Vehicle.h"

Vehicle::Vehicle() // Sets default motion variables to zero
{
	posX = 0; posY = 0; vel = 0;
}

void Vehicle::setPos(int X, int Y)
{
	posX = X; posY = Y;
	this->setLocation(); // Derived class implementation overrides this virtual function when called
}

std::vector<int> Vehicle::getPos()
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

// Checks to see if there has been a change at the specified location and updates character, otherwise returns the same input
char Vehicle::getShapeDelta(int X, int Y, char curr_frame)
{
	if (this->isHere(X, Y))
	{
		return this->getShape(X, Y);
	}
	else return curr_frame;
}