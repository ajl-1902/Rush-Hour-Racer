#include "Borders.h"
using namespace std;

Borders::Borders(int X, int Y, char bdr)
{
	this->setPos(X, Y);
	border = bdr;

	this->setShape(border);
	this->setLocation();
}

void Borders::setShape(int arb)
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		cell[i] = border;
	}
}

char Borders::getShape(int X, int Y)
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		if (cell_pos[i][0] == X && cell_pos[i][1] == Y)
		{
			return cell[i];
		}
	}
}

void Borders::setLocation()
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		cell_pos[i][0] = this->getPos()[0] + i;
		cell_pos[i][1] = this->getPos()[1];
	}
}

bool Borders::isHere(int X, int Y)
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		if (cell_pos[i][0] == X && cell_pos[i][1] == Y) { return true; }
	}
	return false;
}