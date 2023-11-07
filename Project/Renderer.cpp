#include <iostream>
#include "Renderer.h"
using namespace std;

Player player(4);

Renderer::Renderer(int m)
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
		for (int j = 0; j < ScreenSize; j++)
		{
			curr_frame[i][j] = ' ';
			prev_frame[i][j] = ' ';
		}

	//player.setPos(ScreenSize / 2 - 8, ScreenSize / 3);
	player.setPos(36, 28);
	
	Borders left('*', 0, 0);
	Borders centerL('|', 0, ScreenSize / 3);
	Borders centerR('|', 0, 2 * ScreenSize / 3 - 2);
	Borders right('*', 0, ScreenSize - 1);
	borders = { left,centerL,centerR,right };
	//borders.push_back(left);
	//borders.push_back(centerL);
	//borders.push_back(centerR);
	//borders.push_back(right);
	//borders.setShape(m);
}

void Renderer::GenerateFrame()
{
	// clears array for next frame
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
		for (int j = 0; j < ScreenSize; j++)
			curr_frame[i][j] = ' ';

	// loop which fills in the frame with relevant frame info
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
		for (int j = 0; j < ScreenSize; j++)
		{
			// filling in the walls on the outside
			curr_frame[i][j] = borders[0].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[1].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[2].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[3].getShapeDelta(i, j, curr_frame[i][j]);

			// filling in the player, if the space is not a space, function ends and isAlive turns false
			curr_frame[i][j] = player.getShapeDelta(i, j, curr_frame[i][j]);
		}
}

//void Renderer::DisplayFrame()
//{
//	for (int i = 0; i < ScreenSize; i++)
//	{
//		for (int j = 0; j < ScreenSize; j++)
//		{
//			cout << curr_frame[i][j];
//		}
//		cout << "\n";
//	}
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos = { 0,0 };
//	Background draw_background;
//	//draw_background.GameWindow();
//}

void Renderer::DisplayFrame() {

	// generates the current inital frame
	this->GenerateFrame();

	// outputs the inital frame to console
	for (int i = 0; i < 5 * ScreenSize / 8; i++) {
		for (int j = 0; j < ScreenSize; j++) {
			cout << curr_frame[i][j];
		}
		cout << "\n";
	}

	// sets current frame data to previous frame data
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
		for (int j = 0; j < ScreenSize; j++)
			prev_frame[i][j] = curr_frame[i][j];

}

void Renderer::UpdateFrame()
{

}

