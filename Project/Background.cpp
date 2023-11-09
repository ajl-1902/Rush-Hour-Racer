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