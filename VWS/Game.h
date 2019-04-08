#pragma once
#include"World.h"


class Game
{
private:
	World* world;
	bool running;
	Human* player;
	bool playeralive;
	time_t t1;
	time_t t2;
	char blinkchar;
	vec2d nextplrmove;

	void setNextPlrCursor();
public:
	Game(int width,int height);

	bool isRunning();
	void update();
	void handleEvents();
};