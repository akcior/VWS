#pragma once
#include "Plant.h"

class Dandelion :
	public Plant
{
public:
	Dandelion(World* world, FILE* file);
	Dandelion(World* world, vec2d pos);

	bool action() override;
	std::string toString();
};