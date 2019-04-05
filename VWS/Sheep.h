#pragma once
#include"Animal.h"

class Sheep : 
	public Animal
{
public:
	Sheep(World* world, vec2d pos);

	std::string toString() override;
};