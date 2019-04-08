#pragma once
#include"Animal.h"


class Fox :
	public Animal
{
public:
	Fox(World* world, FILE* file);
	Fox(World* world, vec2d pos);

	bool makeMove() override;
	std::string toString() override;
};
