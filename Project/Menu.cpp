#include <iostream>
#include "Menu.h"
#include "Windows.h"
using namespace std;

Menu::Menu()
{
	choice = 0;
	exit = 0;
}

Menu::~Menu() {}

void Menu::BootSequence()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0,0 };
	
	for (int j = 0; j < ScreenSize / 2; j++)
		cout << "* ";
	for (int i = 0; i < ScreenSize / 2 + 4; i++)
	{
		cout << "*";
		pos.X = ScreenSize; pos.Y = i;
		SetConsoleCursorPosition(console, pos);
		cout << "*" << endl;
	}
	for (int j = 0; j < ScreenSize / 2 + 1; j++)
		cout << "* ";

	pos.X = (ScreenSize / 3) - 2; pos.Y = ScreenSize / 6 + 1;
	SetConsoleCursorPosition(console, pos);
	cout << "Rush" << endl;
	Sleep(750);

	pos.X = (ScreenSize / 2) - 2; pos.Y = ScreenSize / 4 + 1;
	SetConsoleCursorPosition(console, pos);
	cout << "Hour" << endl;
	Sleep(750);

	pos.X = (2 * ScreenSize / 3) - 2; pos.Y = 2 * ScreenSize / 6 + 1;
	SetConsoleCursorPosition(console, pos);
	cout << "Racer" << endl;
	Sleep(3000);
	//system("pause");

	system("cls");
	MainMenu();
}

void Menu::MainMenu()
{
	while (!exit)
	{
		cout << "Welcome to Rush Hour Racer!" << endl;
		cout << "1. Play" << endl;
		cout << "2. Difficulty" << endl;
		cout << "3. Customization" << endl;
		cout << "4. How to Play" << endl;
		cout << "5. Exit" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Game Started" << endl;
			break;
		case 2:
			system("cls");
			cout << "Select Difficulty" << endl;
			break;
		case 3:
			system("cls");
			cout << "Player Car" << endl;
			break;
		case 4:
			system("cls");
			cout << "Instructions" << endl;
			break;
		case 5:
			exit = 1;
			break;
		}
	}
}