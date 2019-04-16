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

	void init(int width = 20, int height = 20, int x = 0, int y = 0);
	void init(std::string str);
	void setNextPlrCursor();
public:
	Game();
	//Game(int width = 20,int height = 20, int x = 0, int y = 0);
	//Game(std::string str);
	bool menu();
	bool isRunning();
	void update();
	void draw();
	void handleEvents();
	bool saveBinary(std::string fname);
	bool loadBinary(std::string fname);
	//void setGame();
};