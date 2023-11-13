#include <iostream>
#include "Menu.h"
using namespace std;

// Used to reduce visual clutter while verifying player input
#define ChoiceCheck5 choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5
#define ChoiceCheck4 choice != 1 && choice != 2 && choice != 3 && choice != 4

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursor_pos = { 0,0 };

Menu::Menu()
{
	choice = 0, exit = 0, score = 0;
	difficulty = 1, model = 1;

	dt = 1.0 / static_cast<double>(fps); // Fps variable is an integer, so it is converted to a double to properly define the time step dt
}

void Menu::BootSequence()
{
	// \n is used over endl wherever possible to prevent unnecessary flushing of output buffer - noticeably improves in-game performance
	// Has negligible effect in menus, but is included to maintain a consistent format
	cout << "Please maximize the window before continuing for the best experience\n\n";
	system("pause");
	system("cls");

	Background draw_background;
	draw_background.BootLogo(); // Draws initial splash screen

	cursor_pos = { (ScreenSize / 3) - 2, ScreenSize / 6 + 3 }; // Moves cursor to appropriate location to output text over logo graphics
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

	this->MainMenu(); // Loads main menu
}

void Menu::MainMenu()
{
	while (!exit)
	{
		system("cls");
		do {
			cout << "Welcome to Rush Hour Racer!\n";
			cout << "1. Play\n" << "2. Difficulty\n" << "3. Customization\n" << "4. How to Play\n" << "5. Exit\n";

			cin >> choice;

			if (ChoiceCheck5) // Ensures that player can not enter a numerical value outside of the defined range
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
			this->Instructions();
			break;

		case 5:
			exit = 1; // Exit condition for while loop is satisfied and program ends
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
	game.DisplayFrame(); // Generates first frame

	while (game.checkCollision()) // Game checks for a collision after each frame
	{
		game.LaneSwitch();
		game.NextFrame();
		Sleep(static_cast<int>(1000 * dt)); // Unless dt is massive (which would only occur for fps approaching 0), casting result to an int will not result in loss of information
		game.UpdateFrame();
		score++;
	}

	cursor_pos = { ScreenSize / 2 - 8,ScreenSize / 3 - 2 };
	SetConsoleCursorPosition(console, cursor_pos);
	cout << "Your score: " << score;
	for (int i = 0; i < ScreenSize / 3 + 2; i++) { cout << "\n"; }
	system("pause");
	
	score = 0; // Resets score for subsequent attempts in same program execution
	this->MainMenu();
}

void Menu::DiffSettings()
{
	system("cls");
	do {
		cout << "The difficulty setting affects the speed and density of traffic. Select an option below:\n";
		cout << "1. Easy\n" << "2. Normal\n" << "3. Hard\n" << "4. Insane\n";

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
		cout << "Customize the model for the player car. Note that car model is purely cosmetic and does not affect performance" << "\n";
		cout << "1. Car\n" << "2. Monster Truck\n" << "3. Formula\n" << "4. Tank\n";

		cin >> choice;
		model = choice;

		if (ChoiceCheck4)
		{
			system("cls");
			cout << "Invalid selection. Enter a value from 1-4\n\n";
		}
	} while (ChoiceCheck4);

	this->MainMenu();
}

void Menu::Instructions()
{
	system("cls");
	cout << "The objective of the game is to weave through lanes of oncoming traffic and attempt to survive for as long as possible.\n"
		<< "After beginning a new run, use the left and right arrow keys to move the player car between adjacent lanes.\n"
		<< "You receive 10 points for every second you survive, and there is no finite win condition, so aim for the highest score!\n\n";
	system("pause");

	this->MainMenu();
}