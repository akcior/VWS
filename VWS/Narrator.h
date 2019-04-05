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
	void orgDieBecauseOfOrg(Organism& o1, Organism& o2);
	void orgMultiply(Organism& o);
	void narrate();

};