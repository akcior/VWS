#pragma once
#include"World.h"


class Game
{
private:
	World* world;
	vec2d size;
	bool running;
	Human* player;
	bool playeralive;
	char blinkchar;
	vec2d nextplrmove;

	void setNextPlrCursor();
public:
	Game(int width = 20,int height = 20);
	Game(std::string str);
	bool isRunning();
	void update();
	void handleEvents();
	bool saveBinary(std::string fname);
	bool loadBinary(std::string fname);
	//void setGame();
};