#pragma once
#include "Animal.h"

class Human :
	public Animal
{
private:
	vec2d nextmove;
	int lastpoweruse;
public:
	Human(World* world, vec2d pos);

	void draw() override;
	bool setNextMove(vec2d dir);
	std::string toString() override;
	bool makeMove() override;

};