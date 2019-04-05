#pragma once
#include "Plant.h"
class Grass :
	public Plant
{
public:
	Grass(World* world, vec2d pos);

	std::string toString() override;
};

