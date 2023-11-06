#include <vector>
#include "Player.h"
using namespace std;

Player::Player() {}
Player::~Player() {}

void Player::setShape(int mdl)
{
	for (int i = 0; i < player_sizeX; i++)
		for (int j = 0; j < player_sizeY; j++)
			cell[i][j] = ' ';

	switch (mdl)
	{
	case 1:

	case 2:

	case 3:

	case 4:
																						cell[4][0] = '_';	cell[5][0] = '_';	cell[6][0] = '_';	cell[7][0] = '_';	cell[8][0] = '_';	cell[9][0] = '_';
							cell[1][1] = '_';	cell[2][1] = '_';	cell[3][1] = '|';																															cell[10][1] = '|';	cell[11][1] = '_';	cell[12][1] = '_';
		cell[0][2] = '|';											cell[3][2] = '|';																															cell[10][2] = '|';											cell[13][2] = '|';
		cell[0][3] = '|';	cell[1][3] = '_';	cell[2][3] = '_';	cell[3][3] = '|';	cell[4][3] = '-';	cell[5][3] = '-';	cell[6][3] = '-';	cell[7][3] = '-';	cell[8][3] = '-';	cell[9][3] = '-';	cell[10][3] = '|';	cell[11][3] = '_';	cell[12][3] = '_';	cell[13][3] = '|';
																	cell[3][4] = '|';																															cell[10][4] = '|';
							cell[1][5] = '_';	cell[2][5] = '_';	cell[3][5] = '|';																															cell[10][5] = '|';	cell[11][5] = '_';	cell[12][5] = '_';
		cell[0][6] = '|';											cell[3][6] = '|';																															cell[10][6] = '|';											cell[13][6] = '|';
		cell[0][7] = '|';	cell[1][7] = '_';	cell[2][7] = '_';	cell[3][7] = '|';																															cell[10][7] = '|';	cell[11][7] = '_';	cell[12][7] = '_';	cell[13][7] = '|';
																	cell[3][8] = '|';	cell[4][8] = '_';	cell[5][8] = '_';	cell[6][8] = '_';	cell[7][8] = '_';	cell[8][8] = '_';	cell[9][8] = '_';	cell[10][8] = '|';
		/*     ______
		    __|      |__
		   |  |      |  |
		   |__|------|__|
		  	  |      |
			__|      |__
		   |  |      |  |
		   |__|      |__|
		      |______|  
		*/
	}
}