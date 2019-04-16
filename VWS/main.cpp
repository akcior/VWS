#pragma once
#include"Game.h"
#include<iostream>
#include<conio.h>;


int main()
{
	Game *vws;
	int w, h;
	char c;
	bool start = true, repeat;
	std::string txt;
	FILE* file;
	do
	{
		repeat = false;
		system("CLS");
		std::cout << "NEW GAME = N\n";
		std::cout << "LOAD GAME = L\n";
		std::cout << "EXIT = x\n";
		std::cin >> c;
		switch (c)
		{
		case 'n':
			std::cout << "width: ";
			std::cin >> w;
			std::cout << "height: ";
			std::cin >> h;
			vws = new Game(w, h);
			break;
		case 'l':
			std::cout << "Save name: ";
			std::cin >> txt;
			file = fopen(&txt[0], "rb");
			if (file != NULL)
			{
				vws = new Game(txt);
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
	} while (repeat);
	while (start && vws->isRunning())
	{
		vws->handleEvents();
		vws->update();
	}
	return 0;
}