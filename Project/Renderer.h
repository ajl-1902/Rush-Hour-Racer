#pragma once
#include "Background.h"
#include "Player.h"
#include "Menu.h"
#include "Windows.h"
#include "Borders.h"
using namespace std;

class Renderer
{
private:
	static const int ScreenSize = 72;
	char curr_frame[ScreenSize][ScreenSize];
	char prev_frame[ScreenSize][ScreenSize];
	vector<Borders> borders;

public:
	Renderer(int);
	//~Renderer();

	void GenerateFrame();
	void DisplayFrame();
	void UpdateFrame();
};