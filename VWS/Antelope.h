#pragma once
#include"Animal.h"

class Antelope :
	public Animal
{
public:
	Antelope(World* world, vec2d pos);

	bool dodge() override;
};
