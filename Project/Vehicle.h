#pragma once
#include <vector>

class Vehicle
{
private:
	int posX, posY, vel;
	std::vector<int> pos; // Stores posX and posY in a single container for easier management

public:
	Vehicle();

	void setPos(int, int);
	std::vector<int> getPos();
	void setVel(int);
	int getVel();

	char getShapeDelta(int, int, char);

	// Virtual functions that are uniquely defined/overwritten in the derived classes
	virtual void setShape(int) = 0;
	virtual char getShape(int, int) = 0;
	virtual void setLocation() = 0;
	virtual bool isHere(int, int) = 0;
};