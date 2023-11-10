#include <iostream>
#include "Menu.h"
using namespace std;

#define ChoiceCheck5 choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5
#define ChoiceCheck4 choice != 1 && choice != 2 && choice != 3 && choice != 4

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursor_pos = { 0,0 };

Menu::Menu()
{
	choice = 0, exit = 0, score = 0;
	difficulty = 1, model = 1;

	dt = 1.0 / static_cast<double>(fps);
}

void Menu::BootSequence()
{
	cout << "Please maximize the window before continuing for the best experience\n\n";
	system("pause");
	system("cls");

	Background draw_background;
	draw_background.BootLogo();

	cursor_pos = { (ScreenSize / 3) - 2, ScreenSize / 6 + 3 };
	SetConsoleCursorPosition(console, cursor_pos);
	cout << "Rush\n";
	Sleep(750);

	cursor_pos = { (ScreenSize / 2) - 2, ScreenSize / 4 + 3 };
	SetConsoleCursorPosition(console, cursor_pos);
	cout << "Hour\n";
	Sleep(750);

	cursor_pos = { (2 * ScreenSize / 3) - 2, 2 * ScreenSize / 6 + 3 };
	SetConsoleCursorPosition(console, cursor_pos);
	cout << "Racer\n";
	Sleep(3000);

	this->MainMenu();
}

void Menu::MainMenu()
{
	while (!exit)
	{
		system("cls");
		do {
			cout << "Welcome to Rush Hour Racer!\n";
			cout << "1. Play" << "\n" << "2. Difficulty" << "\n" << "3. Customization" << "\n" << "4. How to Play" << "\n" << "5. Exit" << "\n";

			cin >> choice;

			if (ChoiceCheck5)
			{
				system("cls");
				cout << "Invalid selection. Enter a value from 1-5\n\n";
				Sleep(2000);
			}
		} while (ChoiceCheck5);

		switch (choice)
		{
		case 1:
			this->RunGame();
			break;

		case 2:
			this->DiffSettings();
			break;

		case 3:
			this->CustomizationSettings();
			break;

		case 4:
			system("cls");
			cout << "Instructions\n";
			break;

		case 5:
			exit = 1;
			system("cls");
			cout << "Thanks for playing!\n";
			Sleep(2000);
			break;
		}
	}
}

void Menu::RunGame()
{
	system("cls");

	Renderer game(difficulty, model);
	game.DisplayFrame();

	while (game.checkCollision())
	{
		game.LaneSwitch();
		game.NextFrame();
		Sleep(static_cast<int>(1000 * dt));
		game.UpdateFrame();
		score++;
	}

	cursor_pos = { ScreenSize / 2 - 8,ScreenSize / 3 - 2 };
	SetConsoleCursorPosition(console, cursor_pos);
	cout << "Your score: " << score;
	for (int i = 0; i < ScreenSize / 3 + 2; i++) { cout << "\n"; }
	system("pause");
	
	score = 0;
	this->MainMenu();
}

void Menu::DiffSettings()
{
	system("cls");
	do {
		cout << "The difficulty setting affects the speed and density of traffic. Select an option below:\n";
		cout << "1. Easy" << "\n" << "2. Normal" << "\n" << "3. Hard" << "\n" << "4. Insane" << "\n";

		cin >> choice;
		difficulty = choice;

		if (ChoiceCheck4)
		{
			system("cls");
			cout << "Invalid selection. Enter a value from 1-4\n\n";
		}
	} while (ChoiceCheck4);

	this->MainMenu();
}

void Menu::CustomizationSettings()
{
	system("cls");
	do {
		cout << "Customize the model for the player car. Note that car model is purely cosmetic and does not affect performance" << endl;
		cout << "1. Car" << endl << "2. Monster Truck" << endl << "3. Formula" << endl << "4. Tank" << endl;

		cin >> choice;
		model = choice;

		if (ChoiceCheck4)
		{
			system("cls");
			cout << "Invalid selection. Enter a value from 1-4" << endl << endl;
			Sleep(1000);
		}
	} while (ChoiceCheck4);

	this->MainMenu();
}