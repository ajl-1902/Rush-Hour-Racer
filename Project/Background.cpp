#include <iostream>
#include "Background.h"

void Background::BootLogo() // Not the most concise way to draw logo, but allows for much more flexibility with design changes
{
	Menu window; // Instantiating object from Menu class to gain access to ScreenSize variable
	unsigned int i = 0;

	for (i = 0; i < window.ScreenSize / 2; i++) { std::cout << "* "; }
	std::cout << "\n";

	for (i = 0; i < window.ScreenSize / 24; i++)
	{
		std::cout << "* * * * * *             * * * * * *             * * * * * *           *\n";
	}

	for (i = 0; i < window.ScreenSize / 24; i++)
	{
		std::cout << "*           * * * * * *             * * * * * *             * * * * * *\n";
	}

	for (i = 0; i < window.ScreenSize / 2; i++) { std::cout << "* "; }
	std::cout << "\n";

	for (i = 0; i < 3 * window.ScreenSize / 8 + 2; i++)
	{
		std::cout << "*                                                                     *\n";
	}

	for (i = 0; i < window.ScreenSize / 2; i++) { std::cout << "* "; }
	std::cout << "\n";

	for (i = 0; i < window.ScreenSize / 24; i++)
	{
		std::cout << "* * * * * *             * * * * * *             * * * * * *           *\n";
	}

	for (i = 0; i < window.ScreenSize / 24; i++)
	{
		std::cout << "*           * * * * * *             * * * * * *             * * * * * *\n";
	}

	for (i = 0; i < window.ScreenSize / 2; i++) { std::cout << "* "; }
}