#pragma once
#include"Game.h"

int main()
{
	Game vws;
	
	if (vws.menu())
	{
		while (vws.isRunning())
		{
			vws.update();
			vws.handleEvents();
		}
	}
	system("CLS");
	return 0;
}