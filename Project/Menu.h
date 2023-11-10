#pragma once
#include "Background.h"
#include "Player.h"
#include "Renderer.h"
#include "Windows.h"
using namespace std;

class Menu
{
private:
	int choice;
	bool exit;
	int difficulty;
	int model;
	int score;

public:
	static const int ScreenSize = 72;

	Menu();

	void BootSequence();
	void MainMenu();
	void RunGame();
	void DiffSettings();
	void CustomizationSettings();
};