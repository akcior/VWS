#include "Wolf.h"



Wolf::Wolf(World* world, vec2d pos): Animal(world,WOLF, pos )
{
	initiative = 5;
	strenght = 9;
}

Wolf::Wolf(World* world, FILE* file) : Animal(world, WOLF, file)
{

}

std::string Wolf::toString()
{
	return ("Wolf on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}
