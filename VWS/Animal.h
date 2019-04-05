#pragma once
#include "Organism.h"

class Plant;

class Animal :
	public Organism
{
protected:
	bool strongerThan(Organism& o);
	int moveRange;
public:
	Animal(World* world, species sp, vec2d pos);
	virtual bool action() override;
	virtual bool collision(Organism& org) override;
	virtual bool makeMove();

	~Animal();
};

