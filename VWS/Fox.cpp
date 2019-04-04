#include"Fox.h"

Fox::Fox(World* world, vec2d pos) : Animal(world, FOX, pos)
{
	strenght = 3;
	initiative = 7;
}

bool Fox::makeMove()
{
	vec2d dir;
	species field;
	do {
		dir = World::getRandomDirection();
		field = world->getFieldSpecies(pos + dir);
	} while (field == ERR || (field != FREE && world->getOrganismOnPosition(pos + dir)->getStrenght() > strenght) );

	if (field == FREE)
	{
		pos = pos + dir;
		return true;
	}
	else
	{

		Organism* def = world->getOrganismOnPosition(pos + dir);
		if (collision(*def))
		{
			pos = pos + dir;
			return true;
		}
		else return false;
	}
}