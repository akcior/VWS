#include"Sheep.h"

Sheep::Sheep(World* world, vec2d pos) : Animal(world, SHEEP, pos)
{
	initiative = 4;
	strenght = 4;
}

std::string Sheep::toString()
{
	return ("Sheep on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}