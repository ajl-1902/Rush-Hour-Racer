#pragma once
#include "Background.h"
#include "Player.h"
#include "Menu.h"
#include "Windows.h"
#include "Borders.h"
#include "Traffic.h"
using namespace std;

class Renderer
{
private:
	static const int ScreenSize = 72;
	char curr_frame[ScreenSize][ScreenSize];
	char prev_frame[ScreenSize][ScreenSize];
	vector<Borders> borders;
	Player player;
	vector<Traffic> trffc;
	int model;
	int difficulty;
	int curr_lane;
	int traffic_lane;
	unsigned int frame_index;
	double dt;

public:
	Renderer(int, int);

	void GenerateFrame();
	void DisplayFrame();
	void UpdateFrame();
	void NextFrame();
	void LaneSwitch();
	vector<int> getLanePos(int);
};