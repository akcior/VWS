#pragma once
#include "Plant.h"

class Deadly_berry :
	public Plant
{
public:
	Deadly_berry(World* world, vec2d pos);

	bool collision(Organism& org) override;
	std::string toString() override;
};