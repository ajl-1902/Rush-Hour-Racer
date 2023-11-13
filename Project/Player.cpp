#include <vector>
#include "Player.h"
using namespace std;

Player::Player()
{
	model = 1; // Default player model is basic car unless player selects otherwise

	this->setShape(model);
	this->setLocation();
}

void Player::setShape(int mdl) // Defines character array for current object based on selected model
{
	for (int i = 0; i < player_sizeX; i++)
	{
		for (int j = 0; j < player_sizeY; j++)
		{
			cell[i][j] = ' ';
		}
	}

	switch (mdl)
	{
	case 1:
																				cell[0][4] = '_'; cell[0][5] = '_';	cell[0][6] = '_'; cell[0][7] = '_';	cell[0][8] = '_'; cell[0][9] = '_';	cell[0][10] = '_';
											cell[1][2] = '_'; cell[1][3] = '|';																																   cell[1][11] = '|'; cell[1][12] = '_';
						  cell[2][1] = '|';	cell[2][2] = '_'; cell[2][3] = '|';																																   cell[2][11] = '|'; cell[2][12] = '_'; cell[2][13] = '|';
														      cell[3][3] = '|';	cell[3][4] = '-'; cell[3][5] = '-';	cell[3][6] = '-'; cell[3][7] = '-';	cell[3][8] = '-'; cell[3][9] = '-';	cell[3][10] = '-'; cell[3][11] = '|';
															  cell[4][3] = '|';																																   cell[4][11] = '|';
															  cell[5][3] = '|';																																   cell[5][11] = '|';
											cell[6][2] = '_'; cell[6][3] = '|';	cell[6][4] = '-'; cell[6][5] = '-';	cell[6][6] = '-'; cell[6][7] = '-';	cell[6][8] = '-'; cell[6][9] = '-';	cell[6][10] = '-'; cell[6][11] = '|'; cell[6][12] = '_';
						  cell[7][1] = '|'; cell[7][2] = '_'; cell[7][3] = '|';																																   cell[7][11] = '|'; cell[7][12] = '_'; cell[7][13] = '|';
															  cell[8][3] = '|'; cell[8][4] = '_'; cell[8][5] = '_'; cell[8][6] = '_'; cell[8][7] = '_';	cell[8][8] = '_'; cell[8][9] = '_';	cell[8][10] = '_'; cell[8][11] = '|';

		/*     _______
			 _|       |_
		    |_|       |_|
              |-------|
			  |       |
			  |       |
			 _|-------|_
			|_|       |_|
			  |_______|  
		*/
		break;

	case 2:
																			    cell[0][4] = '_'; cell[0][5] = '_';	cell[0][6] = '_'; cell[0][7] = '_';	cell[0][8] = '_'; cell[0][9] = '_';	cell[0][10] = '_';
						  cell[1][1] = '_';	cell[1][2] = '_'; cell[1][3] = '/';																																   cell[1][11] = '\\'; cell[1][12] = '_'; cell[1][13] = '_';
		cell[2][0] = '|';									  cell[2][3] = '|';																																   cell[2][11] = '|';										cell[2][14] = '|';
		cell[3][0] = '|'; cell[3][1] = '_';	cell[3][2] = '_'; cell[3][3] = '|';	cell[3][4] = '-'; cell[3][5] = '-';	cell[3][6] = '-'; cell[3][7] = '-';	cell[3][8] = '-'; cell[3][9] = '-';	cell[3][10] = '-'; cell[3][11] = '|'; cell[3][12] = '_'; cell[3][13] = '_';	cell[3][14] = '|';
															  cell[4][3] = '|';																																   cell[4][11] = '|';
						  cell[5][1] = '_';	cell[5][2] = '_'; cell[5][3] = '|';																																   cell[5][11] = '|'; cell[5][12] = '_'; cell[5][13] = '_';
		cell[6][0] = '|';									  cell[6][3] = '|';																																   cell[6][11] = '|';										cell[6][14] = '|';
		cell[7][0] = '|'; cell[7][1] = '_'; cell[7][2] = '_'; cell[7][3] = '|';																																   cell[7][11] = '|'; cell[7][12] = '_'; cell[7][13] = '_';	cell[7][14] = '|';
															  cell[8][3] = '|';	cell[8][4] = '_'; cell[8][5] = '_';	cell[8][6] = '_'; cell[8][7] = '_';	cell[8][8] = '_'; cell[8][9] = '_';	cell[8][10] = '_'; cell[8][11] = '|';
		/*     _______
		    __/       \__
		   |  |       |  |
		   |__|-------|__|
		  	  |       |
			__|       |__
		   |  |       |  |
		   |__|       |__|
		      |_______|  
		*/
		break;

	case 3:
																								  cell[0][5] = '_'; cell[0][6] = '_'; cell[0][7] = '_'; cell[0][8] = '_'; cell[0][9] = '_';
																			    cell[1][4] = '/'; cell[1][5] = '_';                                                       cell[1][9] = '_'; cell[1][10] = '\\';
											                  cell[2][3] = '_';                   cell[2][5] = '/';														  cell[2][9] = '\\';                   cell[2][11] = '_';
						                    cell[3][2] = '|'; cell[3][3] = '_'; cell[3][4] = '|';                                     cell[3][7] = '_';                                     cell[3][10] = '|'; cell[3][11] = '_'; cell[3][12] = '|';
														                        cell[4][4] = '|';                   cell[4][6] = '/';                   cell[4][8] = '\\';                  cell[4][10] = '|';
										                      cell[5][3] = '_'; cell[5][4] = '|';                   cell[5][6] = '|'; cell[5][7] = '_'; cell[5][8] = '|';                   cell[5][10] = '|'; cell[5][11] = '_';
						                    cell[6][2] = '|'; cell[6][3] = '_'; cell[6][4] = '|';																							cell[6][10] = '|'; cell[6][11] = '_'; cell[6][12] = '|';
											                  cell[7][3] = '_'; cell[7][4] = '\\';cell[7][5] = '_'; cell[7][6] = '_'; cell[7][7] = '_'; cell[7][8] = '_'; cell[7][9] = '_'; cell[7][10] = '/'; cell[7][11] = '_';
						                    cell[8][2] = '|'; cell[8][3] = '_'; cell[8][4] = '_'; cell[8][5] = '_'; cell[8][6] = '_'; cell[8][7] = '_'; cell[8][8] = '_'; cell[8][9] = '_'; cell[8][10] = '_'; cell[8][11] = '_'; cell[8][12] = '|';
		/*      _____
		       /_   _\
			  _ /   \ _
			 |_|  _  |_|
			   | / \ |
			  _| |_| |_
			 |_|     |_|
			  _\_____/_
			 |_________|
		*/
		break;

	case 4:
																																	  cell[0][7] = '_';
																													cell[1][6] = '|';                   cell[1][8] = '|';
															  cell[2][3] = '_'; cell[2][4] = '_'; cell[2][5] = '_';	cell[2][6] = '|';                   cell[2][8] = '|'; cell[2][9] = '_'; cell[2][10] = '_'; cell[2][11] = '_';
											cell[3][2] = '/';				                                        cell[3][6] = '|';                   cell[3][8] = '|';                                                         cell[3][12] = '\\';
									        cell[4][2] = '|';														cell[4][6] = '|';                   cell[4][8] = '|';                                                         cell[4][12] = '|';
											cell[5][2] = '|';									  cell[5][5] = '/';                                                       cell[5][9] = '\\';                                      cell[5][12] = '|';
											cell[6][2] = '|';									  cell[6][5] = '|';                                                       cell[6][9] = '|';                                       cell[6][12] = '|';
											cell[7][2] = '|';									  cell[7][5] = '\\';cell[7][6] = '_'; cell[7][7] = '_'; cell[7][8] = '_'; cell[7][9] = '/';                                       cell[7][12] = '|';
											cell[8][2] = '\\';cell[8][3] = '_'; cell[8][4] = '_'; cell[8][5] = '_';	cell[8][6] = '_'; cell[8][7] = '_';	cell[8][8] = '_'; cell[8][9] = '_';	cell[8][10] = '_'; cell[8][11] = '_'; cell[8][12] = '/';
		/*        _
                 | |     
			  ___| |___     
		     /   | |   \  
		     |   | |   | 
		     |  /   \  | 
		     |  |   |  | 
		     |  \___/  | 
		     \_________/ 
		*/

		break;
	}
}

char Player::getShape(int X, int Y) // Retrieves character at a certain (X,Y) location
{
	for (int i = 0; i < player_sizeX; i++)
	{
		for (int j = 0; j < player_sizeY; j++)
		{
			if (cell_pos[i][j][0] == X && cell_pos[i][j][1] == Y) { return cell[i][j]; }
		}
	}
}

void Player::setLocation() // Defines the locations of each character in the game window plane
{
	for (int i = 0; i < player_sizeX; i++)
	{
		for (int j = 0; j < player_sizeY; j++)
		{
			cell_pos[i][j][0] = this->getPos()[0] + i;
			cell_pos[i][j][1] = this->getPos()[1] + j;
		}
	}
}

bool Player::isHere(int X, int Y) // Checks is a player character is present at the specified location
{
	for (int i = 0; i < player_sizeX; i++)
	{
		for (int j = 0; j < player_sizeY; j++)
		{
			if (cell_pos[i][j][0] == X && cell_pos[i][j][1] == Y) { return true; }
		}
	}
	return false;
}

void Player::editModel(int mdl) // Allows player model to be overwritten after an object is instantiated
{
	this->setShape(mdl);
	this->setLocation();
}