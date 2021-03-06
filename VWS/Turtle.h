#pragma once
#include"Animal.h"

class Turtle :
	public Animal
{
public:
	Turtle(World* world, FILE* file);
	Turtle(World* world, vec2d pos);

	bool blockTheAttack(Organism& org) override;
	bool action();
	std::string toString() override;
};