#pragma once
#include "Background.h"
#include "Player.h"
#include "Windows.h"
#include "Renderer.h"
using namespace std;

class Menu
{
private:
	int choice;
	bool exit;
	int difficulty;
	int model;

public:
	static const int ScreenSize = 72;
	Menu();
	~Menu();
	void BootSequence();
	void MainMenu();
	void RunGame();
	void DiffSettings();
	void CustomizationSettings();
};