#pragma once
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