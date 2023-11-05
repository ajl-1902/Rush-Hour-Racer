#pragma once
using namespace std;

class Menu
{
private:
	static const int ScreenSize = 96;
	int choice;
	bool exit;
	int difficulty;
	int model;

public:
	Menu();
	~Menu();
	void BootSequence();
	void MainMenu();
	void RunGame();
	void DiffSettings();
	void CustomizationSettings();
	void BootLogo();
};