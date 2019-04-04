#pragma once
#include"Animal.h"


class Fox :
	public Animal
{
public:
	Fox(World* world, vec2d pos);

	bool makeMove() override;
};
