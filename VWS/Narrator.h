#pragma once
#include"World.h"

class Narrator
{
private:
	vec2d dialogPos;
	vec2d dialogSize;
	std::vector<std::string> events;
public:

	Narrator(vec2d wrdframepos, vec2d wrdframesize);
	void orgDieBecauseOfOrg(std::string o1, std::string o2);
	void orgMultiply(std::string o);
	void buff(Organism& o, bool inc, std::string name);
	//void addEvent(std::string str);
	void narrate();

};