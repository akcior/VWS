#pragma once
#include"World.h"


class Game
{
private:
	World* world;
	bool running;

public:
	Game(int width,int height);

	bool isRunning();
	void update();
	void handleEvents();
};