#include <iostream>
#include "Renderer.h"
using namespace std;

Renderer::Renderer(int diff, int mdl)
{
	model = mdl;
	difficulty = diff;

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			curr_frame[i][j] = ' ';
			prev_frame[i][j] = ' ';
		}
	}

	player.editModel(model);
	player.setPos(ScreenSize / 2, ScreenSize / 3 + 4);

	Traffic trffc(difficulty);
	traffic = { trffc };

	Borders left(0, 0, '*');
	Borders centerL(0, ScreenSize / 3, '|');
	Borders centerR(0, 2 * ScreenSize / 3 - 2, '|');
	Borders right(0, ScreenSize - 1, '*');
	borders = { left,centerL,centerR,right };

	curr_lane = 2;
	traffic_lane = 2;
	frame_index = 0;
}

void Renderer::GenerateFrame()
{
	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			curr_frame[i][j] = ' ';
		}
	}

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			curr_frame[i][j] = borders[0].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[1].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[2].getShapeDelta(i, j, curr_frame[i][j]);
			curr_frame[i][j] = borders[3].getShapeDelta(i, j, curr_frame[i][j]);

			for (int k = 0; k < traffic.size(); k++)
			{
				curr_frame[i][j] = traffic[k].getShapeDelta(i, j, curr_frame[i][j]);
			}

			curr_frame[i][j] = player.getShapeDelta(i, j, curr_frame[i][j]);
		}
	}
}

void Renderer::DisplayFrame()
{
	this->GenerateFrame();

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			cout << curr_frame[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < 5 * ScreenSize / 8; i++)
	{
		for (int j = 0; j < ScreenSize; j++)
		{
			prev_frame[i][j] = curr_frame[i][j];
		}
	}

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

	for (int i = 0; i < traffic.size(); i++)
	{
		traffic[i].setPos(traffic[i].getPos()[0] + traffic[i].getVel(), traffic[i].getPos()[1]);
	}

	if ((traffic[0]).getPos()[0] > 2 * ScreenSize / 3)
	{
		traffic.erase(traffic.begin());
	}

	switch (difficulty) // Linear/exponential scaling create impossible densities on higher difficuties - must be set manually
	{
	case 1:
		delay_factor = 25;
		break;
	case 2:
		delay_factor = 20;
		break;
	case 3:
		delay_factor = 10;
		break;
	case 4:
		delay_factor = 7;
		break;
	}

	if (frame_index % (delay_factor) == 0)
	{
		Traffic trffc(difficulty, traffic_lane);
		traffic.push_back(trffc);
		traffic_lane = trffc.getTrafficLane();
	}
}

void Renderer::LaneSwitch()
{
	if (GetAsyncKeyState(VK_LEFT) && curr_lane != 1) { curr_lane -= 1; }

	if (GetAsyncKeyState(VK_RIGHT) && curr_lane != 3) { curr_lane += 1; }
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

bool Renderer::checkCollision()
{
	for (int i = 0; i < traffic.size(); i++)
	{
		if (traffic[i].getPos()[0] >= 28 && traffic[i].getPos()[0] <= 44 && traffic[i].getTrafficLane() == curr_lane)
		{
			return false; // Player is allowed one frame of rear clipping to prevent seemingly off-screen collisions
		}
	}
	return true;
}

