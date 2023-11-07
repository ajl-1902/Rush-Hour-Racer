#include "Borders.h"

Borders::Borders() {}

Borders::Borders(char bdr, int X, int Y)
{
	this->setPos(X, Y);
	this->border = bdr;
	this->setShape(border);
	this->setLocation();
}

void Borders::setShape(int arb)
{
	//for (int j = 0; j < ScreenSize; j++)
	//{
	//	cell[j] = ' ';
	//}

	for (int j = 0; j < 5 * ScreenSize / 8; j++)
	{
		cell[j] = border;
	}

	//for (int i = 0; i < ScreenSize / 18 - 2; i++)
	//{
	//	for (int j = 0; j < ScreenSize; j = j + 2)
	//	{
	//		cell[i][j] = '*';
	//	}
	//}
	//for (int i = ScreenSize / 18 - 1; i < 4 * ScreenSize / 9 + 7; i++)
	//{
	//	cell[i][0] = '*';
	//	cell[i][ScreenSize / 3] = '|';
	//	cell[i][2 * ScreenSize / 3 - 2] = '|';
	//	cell[i][ScreenSize - 1] = '*';
	//}
	//for (int i = 4 * ScreenSize / 9 + 7; i < ScreenSize; i)
	//{
	//	for (int j = 0; j < ScreenSize; j = j + 2)
	//	{
	//		cell[i][j] = '*';
	//	}
	//}
}

char Borders::getShape(int X, int Y)
{
	for (int j = 0; j < 5 * ScreenSize / 8; j++)
	{
		if (cell_pos[j][0] == X && cell_pos[j][1] == Y)
		{
			return cell[j];
		}
	}
}

void Borders::setLocation()
{
	for (int j = 0; j < 5 * ScreenSize / 8; j++)
	{
		cell_pos[j][0] = this->getPos()[0] + j;
		cell_pos[j][1] = this->getPos()[1];
	}
}

bool Borders::isHere(int X, int Y)
{
	for (int j = 0; j < 5 * ScreenSize / 8; j++)
	{
		if (cell_pos[j][0] == X && cell_pos[j][1] == Y) { return true; }
	}
	return false;
}