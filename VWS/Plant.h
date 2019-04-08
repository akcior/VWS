#pragma once
#include "Organism.h"

class Animal;

class Plant :
	public Organism
{
private:
	double multiplyChance;

public:
	Plant(World* world,species sp, FILE* file);
	Plant(World* world, species sp, vec2d pos);
	virtual bool collision(Organism& an) override;
	virtual bool action() override;
	virtual bool tryMultiply() override;
	virtual void saveBinary(FILE* file) override;
	//virtual void multiply() override;
	~Plant();
};

