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
	void clearGame();

	void init(int width = 20, int height = 20, int x = 0, int y = 0);
	void init(std::string str);
	void setNextPlrCursor();
public:
	Game();
	bool menu();
	bool isRunning() const;
	void update();
	void draw() const;
	void handleEvents();
	bool saveBinary(std::string fname) const;
	bool loadBinary(std::string fname);
};