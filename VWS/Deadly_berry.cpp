#include"Deadly_berry.h"
#include"Narrator.h"
Deadly_berry::Deadly_berry(World* world, vec2d pos) : Plant(world, DEADLY_BERRY, pos)
{
	strenght = 99;
}

bool Deadly_berry::collision(Organism& org)
{
	world->narrator.orgDieBecauseOfOrg(this->toString(), org.toString());
	this->die();
	return false;
}

std::string Deadly_berry::toString()
{
	return ("Guarana on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}