#include "Borders.h"

Borders::Borders()
{
	this->setShape(1);
	this->setLocation();
}

void Borders::setShape(int s)
{
	for (int i = 0; i < ScreenSize; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			cell[i][j] = ' ';
		}
	}

	for (int i = 0; i < ScreenSize / 18 - 2; i++)
	{
		for (int j = 0; j < ScreenSize; j = j + 2)
		{
			cell[i][j] = '*';
		}
	}
	for (int i = ScreenSize / 18 - 1; i < 4 * ScreenSize / 9 + 7; i++)
	{
		cell[i][0] = '*';
		cell[i][ScreenSize / 3] = '|';
		cell[i][2 * ScreenSize / 3 - 2] = '|';
		cell[i][ScreenSize - 1] = '*';
	}
	for (int i = 4 * ScreenSize / 9 + 7; i < ScreenSize; i)
	{
		for (int j = 0; j < ScreenSize; j = j + 2)
		{
			cell[i][j] = '*';
		}
	}
}

char Borders::getShape(int X, int Y)
{
	for (int i = 0; i < ScreenSize; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			if (cell_pos[i][j][0] == X && cell_pos[i][j][1] == Y)
				return cell[i][j];
		}
	}
}

void Borders::setLocation()
{
	for (int i = 0; i < ScreenSize; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			cell_pos[i][j][0] = this->getPos()[0] + i;
			cell_pos[i][j][1] = this->getPos()[1] + j;
		}
	}
}

bool Borders::isHere(int X, int Y)
{
	for (int i = 0; i < ScreenSize; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			if (cell_pos[i][j][0] == X && cell_pos[i][j][1] == Y) { return true; }
		}
	}
	return false;
}