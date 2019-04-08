#include "Dandelion.h"

Dandelion::Dandelion(World* world, vec2d pos) : Plant(world, DANDELION, pos)
{

}
Dandelion::Dandelion(World* world, FILE* file) : Plant(world, DANDELION, file)
{

}

bool Dandelion::action()
{
	age++;
	for (int i = 0; i < 3; i++)
	{
		if (tryMultiply() && age > 1)
		{
			multiply();
		}
	}
	return true;
}

std::string Dandelion::toString()
{
	return ("Dandelion on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}