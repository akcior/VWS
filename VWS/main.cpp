#pragma once
#include"Game.h"
#include<iostream>


int main()
{
	Game *vws;
	int w, h;
	char c;
	std::string txt;
	std::cout << "NEW GAME = N\n";
	std::cout << "LOAD GAME = L\n";
	std::cin >> c;
	if (c == 'n')
	{
		std::cout << "width: ";
		std::cin >> w;
		std::cout << "height: ";
		std::cin >> h;
		vws = new Game(w, h);
	}
	else if (c == 'l')
	{
		std::cout << "Save name: ";
		std::cin >> txt;
		vws = new Game(txt);
	}
	while (vws->isRunning())
	{
		vws->handleEvents();
		vws->update();
	}
	return 0;
}