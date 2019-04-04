#include"Sheep.h"

Sheep::Sheep(World* world, vec2d pos) : Animal(world, SHEEP, pos)
{
	initiative = 4;
	strenght = 4;
}