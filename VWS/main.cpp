#pragma once
//#include"World.h"
#include"Game.h"
#include<iostream>


int main()
{
	Game vws(20,20);
	while (vws.isRunning())
	{
		vws.update();
		vws.handleEvents();
	}
	return 0;
}