#include "Grass.h"



Grass::Grass(World* world, vec2d pos): Plant(world,GRASS, pos)
{

}

Grass::Grass(World* world, FILE* file) : Plant(world, GRASS, file)
{

}

std::string Grass::toString()
{
	return ("Grass on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}
