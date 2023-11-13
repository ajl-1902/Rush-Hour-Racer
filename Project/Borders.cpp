#include "Borders.h"
using namespace std;

Borders::Borders(int X, int Y, char bdr) // Game window is made up of two different characters, so the object must be instantiated with the character it plans to use
{
	this->setPos(X, Y);
	border = bdr;

	this->setShape(border);
	this->setLocation();
}

void Borders::setShape(int arb) // Defines character array for current object
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		cell[i] = border; // Border has a fixed X location, so only need to step through Y to fill character array
	}
}

char Borders::getShape(int X, int Y) // Retrieves character at a certain (X,Y) location
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		if (cell_pos[i][0] == X && cell_pos[i][1] == Y)
		{
			return cell[i];
		}
	}
}

void Borders::setLocation() // Defines the locations of each character in the game window plane
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		cell_pos[i][0] = this->getPos()[0] + i;
		cell_pos[i][1] = this->getPos()[1];
	}
}

bool Borders::isHere(int X, int Y) // Checks if there is a character present at the requested location - not used in relation to border class (only here to override virtual function in base class)
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		if (cell_pos[i][0] == X && cell_pos[i][1] == Y) { return true; }
	}
	return false;
}