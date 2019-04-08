#include"Guarana.h"
#include"Narrator.h"

Guarana::Guarana(World * world, vec2d pos) : Plant(world, GUARANA, pos)
{

}

bool Guarana::collision(Organism& org)
{
	world->narrator.orgDieBecauseOfOrg(this->toString(), org.toString());
	org.addStrenght(3);
	this->die();
	return true;
}

std::string Guarana::toString()
{
	return ("Guarana on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}