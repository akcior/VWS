#pragma once
#include "Plant.h"

class Guarana :
	public Plant
{
public:
	Guarana(World* world, vec2d pos);

	bool collision(Organism& org) override;
	std::string toString() override;

};