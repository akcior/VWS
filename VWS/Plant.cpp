#include "Plant.h"
#include "Narrator.h"



Plant::Plant(World* world, species sp, vec2d pos) : Organism(world,sp, pos)
{
	initiative = 0;
	strenght = 0;
	multiplyChance = 0.03;
}
bool Plant::collision(Organism& an)
{
	world->narrator.orgDieBecauseOfOrg(this->toString(), an.toString());
	this->die();
	return true;
}
bool Plant::tryMultiply()
{
	int t = rand() % 100;

	if (t <= multiplyChance * 100) return true;
	else return false;
}

bool Plant::action() {
	age++;
	if (tryMultiply() && age > 1)
	{
		multiply();
	}
	return true;
}

Plant::~Plant()
{
}
