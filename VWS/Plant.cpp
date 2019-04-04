#include "Plant.h"



Plant::Plant(World* world, species sp, vec2d pos) : Organism(world,sp, pos)
{
	initiative = 0;
	strenght = 0;
	multiplyChance = 0.05;
}
bool Plant::collision(Organism& an)
{
	this->die();
	return true;
}
bool Plant::tryMultiply()
{
	int t = rand() % 100;

	if (t <= multiplyChance * 100) return true;
	else return false;
}

void Plant::action() {
	age++;
	if (tryMultiply() && age > 1)
	{
		multiply();
	}
}

Plant::~Plant()
{
}
