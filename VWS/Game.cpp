#include"Game.h"
#include<conio.h>
#include<iostream>
#include"ConsolePrinter.h"
#include"Human.h"

Game::Game()
{

}

void Game::init(int width, int height, int x, int y)
{
	size = vec2d(width, height);
	pos = vec2d(x, y);
	world = new World(vec2d(width, height),vec2d(0,0));
	player = world->getHuman();
	if (player != nullptr) playeralive = true;
	else playeralive = false;
	running = true;
	ConsolePrinter::showCursor(false);
	nextplrmove = vec2d(0, 0);

	system("CLS");
	ConsolePrinter::printFrame('+', 0, 0, size.x + 2, size.y + 2);
	world->nextRound();
	world->draw();
}

void Game::init(std::string str)
{
	loadBinary(str);
	player = world->getHuman();
	if (player != nullptr) playeralive = true;
	else playeralive = false;
	running = true;
	size = world->getWorldSize();
	pos = world->getFramePos();
	ConsolePrinter::showCursor(false);
	nextplrmove = vec2d(0, 0);
	system("CLS");
	ConsolePrinter::printFrame('+', 0, 0, size.x + 2, size.y + 2);
	world->draw();
}
bool Game::menu()
{
	int w, h;
	char c;
	bool start = true, repeat;
	std::string txt;
	FILE* file;
		system("CLS");
		std::cout << "NEW GAME = N\n";
		std::cout << "LOAD GAME = L\n";
		std::cout << "EXIT = X\n";
	do
	{
		repeat = false;
		if (_kbhit())
		{
			system("CLS");
			std::cout << "NEW GAME = N\n";
			std::cout << "LOAD GAME = L\n";
			std::cout << "EXIT = X\n";

			c = _getch();
			switch (c)
			{
			case 'n':
				std::cout << "width: ";
				std::cin >> w;
				std::cout << "height: ";
				std::cin >> h;
				if (w >= 20 && h >= 20)
				{
					init(w, h);
				}
				else 
				{
					std::cout << "Wrong size!!(minimum size is 20x20)";
					repeat = true;
				}
				break;
			case 'l':
				std::cout << "Save name: ";
				std::cin >> txt;
				file = fopen(&txt[0], "rb");
				if (file != NULL)
				{
					init(txt);
					fclose(file);
				}
				else
				{
					std::cout << "Save not found!\n";
					repeat = true;
					_getch();
				}
				break;
			case 'x':
				start = false;
				break;
			default:
				repeat = true;
				break;
			}
		}
		else repeat = true;

	} while (repeat);
	return start;
}

bool Game::isRunning()
{
	return running;
}

void Game::clearGame()
{
	delete world;
	player = nullptr;
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
	
}
void Game::draw()
{
	system("CLS");
	ConsolePrinter::printFrame('+', pos.x, pos.y, size.x + 2, size.y + 2);
	world->draw();
}

void Game::handleEvents()
{
	char c;
	if (_kbhit())
	{
		c = _getch();
		if (_kbhit())	//handle special keys
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
			
		}
		else
		{
			switch (c) {
			case 'n':
				world->nextRound();
				system("CLS");
				draw();
				//ConsolePrinter::printFrame('o', 22,0, 22, 22);
				if (playeralive)
				{
					player = world->getHuman();
					if (player == nullptr) playeralive = false;
				}
				break;
			case 'x':
				running = false;
				clearGame();
				break;
			case 'c': 
				system("CLS");
				break;
			case 'p':
				player->useSuperPower();
				break;
			case 's':
				ConsolePrinter::goToXY(pos.x + size.x + 3, 0);
				ConsolePrinter::writeString("Give name to your world:");
				ConsolePrinter::showCursor(true);
				std::string str;
				std::cin >> str;
				ConsolePrinter::showCursor(false);
				saveBinary(str);
				ConsolePrinter::goToXY(pos.x + size.x + 3, 1);
				ConsolePrinter::writeString("GAME SAVED!!");
				_getch();
				draw();
			
			}
		}
	}
}

bool Game::saveBinary(std::string fname)
{
	FILE* file = fopen(&fname[0], "wb");
	if (file != NULL)
	{
		world->saveBinary(file);
		fclose(file);
		return true;
	}
	return false;
}
bool Game::loadBinary(std::string fname)
{
	FILE* file = fopen(&fname[0], "rb");
	if (file != NULL)
	{
		//delete world;
		world = new World(file);
		fclose(file);
		return true;
	}
	return false;
}