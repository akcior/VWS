#include"Game.h"
#include<conio.h>
#include<iostream>
#include"ConsolePrinter.h"

Game::Game(int width, int height)
{
	world = new World(vec2d(width, height),vec2d(0,0));
	running = true;
	ConsolePrinter::hideCursor();
}

bool Game::isRunning()
{
	return running;
}

void Game::update()
{
	//ConsolePrinter::printFrame('o', 1, 1, 5, 5);
	//world->nextRound();
	//system("CLS");
	//world->draw();
}

void Game::handleEvents()
{
	char c;
	if (_kbhit())
	{
		c = _getch();
		if (_kbhit())
		{
			c = _getch();
			std::cout << c;
			//handle special keys
		}
		else
		{
			if (c == 'n')
			{
				system("CLS");
				ConsolePrinter::printFrame('+', 0, 0, 22, 22);
				//ConsolePrinter::printFrame('o', 22,0, 22, 22);
				world->nextRound();
				world->draw();
				/*char c = ConsolePrinter::getConsoleChar(0, 0);
				ConsolePrinter::goToXY(40, 25);
				ConsolePrinter::writeChar(c);
				ConsolePrinter::goToXY(23, 23);*/
			}
			else if (c == 'x') running = false;
			else if (c == 'c') system("CLS");
		}
	}
}