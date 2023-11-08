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
	player.setPos(ScreenSize / 2, ScreenSize / 3 + 4);
	
	Traffic traffic;
	trffc.push_back(traffic);

	Borders left('*', 0, 0);
	Borders centerL('|', 0, ScreenSize / 3);
	Borders centerR('|', 0, 2 * ScreenSize / 3 - 2);
	Borders right('*', 0, ScreenSize - 1);
	borders = { left,centerL,centerR,right };

	curr_lane = 2;
	traffic_lane = 2;
	frame_index = 0;
	dt = 0.1;
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

			for (int k = 0; k < trffc.size(); k++)
			{
				curr_frame[i][j] = trffc[k].getShapeDelta(i, j, curr_frame[i][j]);
			}

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
	this->GenerateFrame();

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			if (prev_frame[i][j] != curr_frame[i][j])
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				COORD cursor_pos = { j, i };
				SetConsoleCursorPosition(hConsole, cursor_pos);
				cout << curr_frame[i][j];
			}
		}
	}

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			prev_frame[i][j] = curr_frame[i][j];
		}
	}
}

void Renderer::NextFrame()
{
	frame_index++;
	player.setPos(this->getLanePos(curr_lane)[0], this->getLanePos(curr_lane)[1]);

	for (int i = 0; i < trffc.size(); i++)
	{
		trffc[i].setPos(trffc[i].getPos()[0] + 1, trffc[i].getPos()[1]);
	}

	if ((trffc[0]).getPos()[0] > ScreenSize)
	{
		trffc.erase(trffc.begin());
	}

	if (frame_index % (30) == 0)
	{
		Traffic traffic(traffic_lane);
		trffc.push_back(traffic);
	}
}

void Renderer::LaneSwitch()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (curr_lane != 1)
		{
			curr_lane -= 1;
		}
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (curr_lane != 3)
		{
			curr_lane += 1;
		}
	}
}

vector<int> Renderer::getLanePos(int curr_lane)
{
	switch (curr_lane)
	{
	case 1:
		return { ScreenSize / 2,ScreenSize / 6 - 7 };
	case 2:
		return { ScreenSize / 2,ScreenSize / 3 + 4 };
	case 3:
		return { ScreenSize / 2, 5 * ScreenSize / 6 - 8 };
	}
}

