#pragma once
using namespace std;

class Menu
{
private:
	static const int ScreenSize = 48;
	int choice;
	bool exit;

public:
	Menu();
	~Menu();
	void BootSequence();
	void MainMenu();
};