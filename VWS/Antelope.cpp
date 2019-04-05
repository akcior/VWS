#include"Antelope.h"

Antelope::Antelope(World* world, vec2d pos) : Animal(world, ANTELOPE, pos)
{
	initiative = 4;
	strenght = 4;
	moveRange = 2;
}

bool Antelope::dodge()
{
	if ((rand() % 100) < 50)
	{
		vec2d dir = world->getRandomFreePosAround(pos);

		if (dir == vec2d(0, 0)) return false;

		pos = pos + dir;

		return true;
	}
	return false;
}

std::string Antelope::toString()
{
	return ("Antelope on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}