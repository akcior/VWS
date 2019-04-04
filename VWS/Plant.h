#pragma once
#include "Organism.h"

class Animal;

class Plant :
	public Organism
{
public:
	Plant(World* world, species sp, vec2d pos);
	bool collision(Organism& an) override ;
	void action() override;
	void multiply() override;
	~Plant();
};

