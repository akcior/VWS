#pragma once
#include "Animal.h"

class Animal;

class Wolf :
	public Animal
{
public:
	Wolf(World* world, vec2d pos);
	~Wolf();
};

