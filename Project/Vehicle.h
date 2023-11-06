#pragma once
#include <vector>
using namespace std;

class Vehicle
{
private:

public:
	Vehicle();
	~Vehicle();

	void setPos(int, int);
	vector<int> getPos();

	virtual void setShape() = 0;
	virtual char getShape() = 0;
};