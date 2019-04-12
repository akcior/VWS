#pragma once
#include"World.h"


class Game
{
private:
	World* world;
	vec2d size;
	vec2d pos;
	bool running;
	Human* player;
	bool playeralive;
	char blinkchar;
	vec2d nextplrmove;

	void setNextPlrCursor();
public:
	Game(int width = 20,int height = 20, int x = 0, int y = 0);
	Game(std::string str);
	bool isRunning();
	void update();
	void handleEvents();
	bool saveBinary(std::string fname);
	bool loadBinary(std::string fname);
	//void setGame();
};