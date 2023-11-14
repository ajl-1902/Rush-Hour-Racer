#pragma once
#include "Background.h"
#include "Player.h"
#include "Renderer.h"
#include "Windows.h"

class Menu
{
private:
	int choice;
	bool exit;
	int difficulty;
	int model;
	int score;
	const int fps = 10; // Number of times the frame is updated per second
	double dt;

public:
	static const int ScreenSize = 72; // Defines edges of game window

	Menu();

	void BootSequence();
	void MainMenu();
	void RunGame();
	void DiffSettings();
	void CustomizationSettings();
	void Instructions();
};