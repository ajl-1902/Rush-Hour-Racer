#pragma once
#include "Background.h"
#include "Menu.h"
#include "Player.h"
#include "Borders.h"
#include "Traffic.h"
#include "Windows.h"

class Renderer
{
private:
	static const int ScreenSize = 72;

	char curr_frame[ScreenSize][ScreenSize]; // Stores all characters in current frame
	char prev_frame[ScreenSize][ScreenSize]; // Stores all characters in previous frame

	Player player;
	std::vector<Borders> borders;
	std::vector<Traffic> traffic;

	int model;
	int difficulty;
	int curr_lane;
	int traffic_lane;
	int delay_factor = 20;

	unsigned int frame_index; // Counts frames that have passed since game began

public:
	Renderer(int, int);

	void GenerateFrame();
	void DisplayFrame();
	void UpdateFrame();
	void NextFrame();

	void LaneSwitch();
	std::vector<int> getLanePos(int);
	bool checkCollision();
};