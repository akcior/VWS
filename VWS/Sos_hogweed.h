#pragma once
#include"Plant.h"

class Sos_hogweed :
	public Plant
{
public:
	Sos_hogweed(World* world, FILE* file);
	Sos_hogweed(World* world, vec2d pos);
	bool action() override;
	bool collision(Organism& org) override;
	std::string toString() override;
};