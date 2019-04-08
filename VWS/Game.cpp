#include"Game.h"
#include<conio.h>
#include<iostream>
#include"ConsolePrinter.h"
#include"Human.h"

Game::Game(int width, int height)
{
	world = new World(vec2d(width, height),vec2d(0,0));
	player = world->getHuman();
	if (player != nullptr) playeralive = true;
	else playeralive = false;
	running = true;
	ConsolePrinter::hideCursor();
	time(&t1);
	nextplrmove = vec2d(0, 0);

	system("CLS");
	ConsolePrinter::printFrame('+', 0, 0, 22, 22);
	world->nextRound();
	world->draw();
}

bool Game::isRunning()
{
	return running;
}
void Game::setNextPlrCursor()
{
	vec2d plrpos = player->getPos();
	if (!(nextplrmove == player->getNextMove()))
	{
		blinkchar = ConsolePrinter::getConsoleChar(plrpos.x + nextplrmove.x + 1, plrpos.y + nextplrmove.y + 1);
		ConsolePrinter::setTheme(WHITE_ON_BLACK);
		ConsolePrinter::goToXY(plrpos.x + nextplrmove.x + 1, plrpos.y + nextplrmove.y + 1);
		ConsolePrinter::writeChar(blinkchar);
	}

	nextplrmove = player->getNextMove();
	ConsolePrinter::setTheme(RED_ON_BLUE);
	blinkchar = ConsolePrinter::getConsoleChar(plrpos.x + nextplrmove.x + 1, plrpos.y + nextplrmove.y + 1);
	ConsolePrinter::goToXY(plrpos.x + nextplrmove.x + 1, plrpos.y + nextplrmove.y + 1);
	ConsolePrinter::writeChar(blinkchar);
	ConsolePrinter::setTheme(WHITE_ON_BLACK);
}

void Game::update()
{
	if(playeralive) setNextPlrCursor();
	//time(&t2);
	////std::cout << difftime(t1, t2);
	////if (difftime(t2, t1) > 0.1)
	////{
	//	vec2d plrnextpos = player->getNextMove();
	//	if (!(plrnextpos == vec2d(0, 0)))
	//	{
	//		vec2d plrpos = player->getPos();
	//		blinkchar = ConsolePrinter::getConsoleChar(plrpos.x + plrnextpos.x + 1, plrpos.y + plrnextpos.y + 1);
	//		if (!blink)
	//		{
	//			ConsolePrinter::setTheme(RED_ON_BLUE);
	//			ConsolePrinter::goToXY(plrpos.x + plrnextpos.x + 1, plrpos.y + plrnextpos.y + 1);
	//			ConsolePrinter::writeChar(blinkchar);
	//			ConsolePrinter::setTheme(WHITE_ON_BLACK);
	//			blink = true;
	//		}
	//		else
	//		{
	//			ConsolePrinter::setTheme(WHITE_ON_BLACK);
	//			ConsolePrinter::goToXY(plrpos.x + plrnextpos.x + 1, plrpos.y + plrnextpos.y + 1);
	//			ConsolePrinter::writeChar(blinkchar);
	//			//ConsolePrinter::setTheme(RED_ON_BLUE);
	//			blink = false;
	//		}
	////	t1 = t2;
	//	}
	//	//todo
	////}
	////ConsolePrinter::printFrame('o', 1, 1, 5, 5);
	////world->nextRound();
	////system("CLS");
	////world->draw();
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
			if (playeralive)
			{
				switch (c)
				{
				case 'H':
					player->setNextMove(vec2d(0, -1));
					break;
				case 'M':
					player->setNextMove(vec2d(1, 0));
					break;
				case 'P':
					player->setNextMove(vec2d(0, 1));
					break;
				case'K':
					player->setNextMove(vec2d(-1, 0));
					break;
				}
			}
			//setNextPlrCursor();
			//nextplrmove = player->
			//std::cout << c;
			//handle special keys
		}
		else
		{
			if (c == 'n')
			{
				system("CLS");
				ConsolePrinter::printFrame('+', 0, 0, 22, 22);
				world->nextRound();
				world->draw();
				//ConsolePrinter::printFrame('o', 22,0, 22, 22);
				if (playeralive)
				{
					player = world->getHuman();
					if (player == nullptr) playeralive = false;
				}
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