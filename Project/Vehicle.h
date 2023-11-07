#pragma once
#include <vector>
using namespace std;

class Vehicle
{
private:
	int posX, posY, vel;
	vector<int> pos;

public:
	Vehicle();

	void setPos(int, int);
	vector<int> getPos();
	void setVel(int);
	int getVel();
	char getShapeDelta(int, int, char);

	virtual void setShape(int) = 0;
	virtual char getShape(int, int) = 0;
	virtual void setLocation() = 0;
	virtual bool isHere(int, int) = 0;
};