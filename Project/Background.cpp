#include <iostream>
#include "Background.h"
using namespace std;

void Background::BootLogo()
{
	Menu window;
	unsigned int i = 0;
	for (i = 0; i < window.ScreenSize / 2; i++) { cout << "* "; }
	cout << "\n";
	for (i = 0; i < window.ScreenSize / 24; i++)
	{
		cout << "* * * * * *             * * * * * *             * * * * * *           *\n";
	}
	for (i = 0; i < window.ScreenSize / 24; i++)
	{
		cout << "*           * * * * * *             * * * * * *             * * * * * *\n";
	}
	for (i = 0; i < window.ScreenSize / 2; i++) { cout << "* "; }
	cout << "\n";
	for (i = 0; i < 3 * window.ScreenSize / 8 + 2; i++)
	{
		cout << "*                                                                     *\n";
	}
	for (i = 0; i < window.ScreenSize / 2; i++) { cout << "* "; }
	cout << "\n";
	for (i = 0; i < window.ScreenSize / 24; i++)
	{
		cout << "* * * * * *             * * * * * *             * * * * * *           *\n";
	}
	for (i = 0; i < window.ScreenSize / 24; i++)
	{
		cout << "*           * * * * * *             * * * * * *             * * * * * *\n";
	}
	for (i = 0; i < window.ScreenSize / 2; i++) { cout << "* "; }
}

//Menu window;
//unsigned int j = 0;
//for (j = 0; j < window.ScreenSize / 18 - 2; j++)
//{
//	for (int k = 0; k < window.ScreenSize / 2; k++) { cout << "* "; }
//	cout << "\n";
//}
//for (j = 0; j < 4 * window.ScreenSize / 9 + 7; j++)
//{
//	cout << "*                       |                     |                       *\n";
//}
//for (j = 0; j < window.ScreenSize / 18 - 2; j++)
//{
//	for (int k = 0; k < window.ScreenSize / 2; k++) { cout << "* "; }
//	cout << "\n";
//}