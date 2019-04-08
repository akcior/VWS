#include"Guarana.h"
#include"Narrator.h"

Guarana::Guarana(World * world, vec2d pos) : Plant(world, GUARANA, pos)
{

}

Guarana::Guarana(World* world, FILE* file) : Plant(world, GUARANA, file)
{

}

bool Guarana::collision(Organism& org)
{
	org.addStrenght(3);
	//world->narrator.orgDieBecauseOfOrg(this->toString(), org.toString());
	//this->die();
	return Plant::collision(org);
	//return true;
}

std::string Guarana::toString()
{
	return ("Guarana on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}