#include <iostream>
#include "Menu.h"
#include "Windows.h"
using namespace std;

#define ChoiceCheck5 choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5
#define ChoiceCheck4 choice != 1 && choice != 2 && choice != 3 && choice != 4

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursor_pos = { 0,0 };

Menu::Menu()
{
	choice = 0;
	exit = 0;
	difficulty = 1;
	model = 1;
}

Menu::~Menu() {}

void Menu::BootSequence()
{
	cout << "Please maximize the window before continuing for the best experience" << endl << endl;
	system("pause");
	system("cls");

	BootLogo();

	cursor_pos.X = (ScreenSize / 3) - 3; cursor_pos.Y = ScreenSize / 6 + 2;
	SetConsoleCursorPosition(console, cursor_pos);
	cout << "Rush" << endl;
	Sleep(750);

	cursor_pos.X = (ScreenSize / 2) - 3; cursor_pos.Y = ScreenSize / 4 + 2;
	SetConsoleCursorPosition(console, cursor_pos);
	cout << "Hour" << endl;
	Sleep(750);

	cursor_pos.X = (2 * ScreenSize / 3) - 3; cursor_pos.Y = 2 * ScreenSize / 6 + 2;
	SetConsoleCursorPosition(console, cursor_pos);
	cout << "Racer" << endl;
	Sleep(3000);
	system("pause");

	MainMenu();
}

void Menu::MainMenu()
{
	while (!exit)
	{
		system("cls");
		do {
			cout << "Welcome to Rush Hour Racer!" << endl;
			cout << "1. Play" << endl << "2. Difficulty" << endl << "3. Customization" << endl << "4. How to Play" << endl << "5. Exit" << endl;

			cin >> this->choice;

			if (ChoiceCheck5)
			{
				system("cls");
				cout << "Invalid selection. Enter a value from 1-5" << endl << endl;
				Sleep(2000);
			}
		} while (ChoiceCheck5);

		switch (choice)
		{
		case 1:
			RunGame();
			break;
		case 2:
			DiffSettings();
			break;
		case 3:
			CustomizationSettings();
			break;
		case 4:
			system("cls");
			cout << "Instructions" << endl;
			break;
		case 5:
			exit = 1;
			system("cls");
			cout << "Thanks for playing!" << endl;
			Sleep(2000);
			break;
		}
	}
}

void Menu::RunGame()
{
	system("cls");
	cout << "    ______" << endl;
	cout << " __|      |__" << endl;
	cout << "|  |      |  |" << endl;
	cout << "|__|------|__|" << endl;
	cout << "   |      |" << endl;
	cout << " __|      |__" << endl;
	cout << "|  |      |  |" << endl;
	cout << "|__|      |__|" << endl;
	cout << "   |______|  " << endl;
	system("pause");
	MainMenu();
}

void Menu::DiffSettings()
{
	system("cls");
	do {
		cout << "Difficulty setting controls the overall frequency and density of traffic. Select an option below:" << endl;
		cout << "1. Easy" << endl << "2. Normal" << endl << "3. Hard" << endl << "4. Insane" << endl;

		cin >> this->choice;
		this->difficulty = choice;

		if (ChoiceCheck4)
		{
			system("cls");
			cout << "Invalid selection. Enter a value from 1-4" << endl << endl;
			Sleep(1000);
		}
	} while (ChoiceCheck4);

	MainMenu();
}

void Menu::CustomizationSettings()
{
	system("cls");
	do {
		cout << "Customize the model for the player car. Note that car model is purely cosmetic and does not affect performance" << endl;
		cout << "1. Car" << endl << "2. Jeep" << endl << "3. Formula" << endl << "4. Monster Truck" << endl;

		cin >> this->choice;
		this->model = choice;

		if (ChoiceCheck4)
		{
			system("cls");
			cout << "Invalid selection. Enter a value from 1-4" << endl << endl;
			Sleep(1000);
		}
	} while (ChoiceCheck4);
}

void Menu::BootLogo()
{
	unsigned int i = 0;
	for (i = 0; i < ScreenSize / 2; i++) { cout << "* "; }
	cout << endl;
	for (i = 0; i < ScreenSize / 24; i++)
	{
		cout << "* * * * * *             * * * * * *             * * * * * *           *" << endl;
	}
	for (i = 0; i < ScreenSize / 24; i++)
	{
		cout << "*           * * * * * *             * * * * * *             * * * * * *" << endl;
	}
	for (i = 0; i < ScreenSize / 2; i++) { cout << "* "; }
	cout << endl;
	for (i = 0; i < 3 * ScreenSize / 8; i++)
	{
		cout << "*                                                                     *" << endl;
	}
	for (i = 0; i < ScreenSize / 2; i++) { cout << "* "; }
	cout << endl;
	for (i = 0; i < ScreenSize / 24; i++)
	{
		cout << "* * * * * *             * * * * * *             * * * * * *           *" << endl;
	}
	for (i = 0; i < ScreenSize / 24; i++)
	{
		cout << "*           * * * * * *             * * * * * *             * * * * * *" << endl;
	}
	for (i = 0; i < ScreenSize / 2; i++) { cout << "* "; }
}