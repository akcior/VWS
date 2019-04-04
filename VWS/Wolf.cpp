#include "Wolf.h"



Wolf::Wolf(World* world, vec2d pos): Animal(world,WOLF, pos )
{
	initiative = 5;
	strenght = 9;
}


Wolf::~Wolf()
{
}
