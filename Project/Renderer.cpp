#include <iostream>
#include "Renderer.h"
using namespace std;

Renderer::Renderer(int diff, int mdl)
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
		for (int j = 0; j < ScreenSize; j++)
		{
			curr_frame[i][j] = ' ';
			prev_frame[i][j] = ' ';
		}

	player.editModel(mdl);
	this->model = mdl;
	player.setPos(36, 28);
	
	Borders left('*', 0, 0);
	Borders centerL('|', 0, ScreenSize / 3);
	Borders centerR('|', 0, 2 * ScreenSize / 3 - 2);
	Borders right('*', 0, ScreenSize - 1);
	borders = { left,centerL,centerR,right };
}

void Renderer::GenerateFrame()
{
	player.editModel(model);

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
		for (int j = 0; j < ScreenSize; j++)
			curr_frame[i][j] = ' ';

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
		for (int j = 0; j < ScreenSize; j++)
		{
			curr_frame[i][j] = borders[0].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[1].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[2].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[3].getShapeDelta(i, j, curr_frame[i][j]);

			curr_frame[i][j] = player.getShapeDelta(i, j, curr_frame[i][j]);
		}
}

void Renderer::DisplayFrame()
{
	this->GenerateFrame();

	for (int i = 0; i < 5 * ScreenSize / 8; i++) {
		for (int j = 0; j < ScreenSize; j++) {
			cout << curr_frame[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
		for (int j = 0; j < ScreenSize; j++)
			prev_frame[i][j] = curr_frame[i][j];

}

void Renderer::UpdateFrame()
{

}

