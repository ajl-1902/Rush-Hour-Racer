#pragma once
#include "Background.h"
#include "Menu.h"
#include "Player.h"
#include "Borders.h"
#include "Traffic.h"
#include "Windows.h"
using namespace std;

class Renderer
{
private:
	static const int ScreenSize = 72;

	char curr_frame[ScreenSize][ScreenSize]; // Stores all characters in current frame
	char prev_frame[ScreenSize][ScreenSize]; // Stores all characters in previous frame

	Player player;
	vector<Borders> borders;
	vector<Traffic> traffic;

	int model;
	int difficulty;
	int curr_lane;
	int traffic_lane;
	int delay_factor;

	unsigned int frame_index; // Counts frames that have passed since game began

public:
	Renderer(int, int);

	void GenerateFrame();
	void DisplayFrame();
	void UpdateFrame();
	void NextFrame();

	void LaneSwitch();
	vector<int> getLanePos(int);
	bool checkCollision();
};