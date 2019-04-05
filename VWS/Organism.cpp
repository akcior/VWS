#include "Organism.h"
#include "ConsolePrinter.h"
#include<map>


Organism::Organism(World* world, species sp, vec2d pos): mySpecies(sp), world(world), pos(pos)
{
	alive = true;
	age = 0;
}

void Organism::draw() {
	vec2d drawPos = world->getFramePos() + pos + vec2d(1, 1);
	ConsolePrinter::goToXY(drawPos.x, drawPos.y);
	ConsolePrinter::writeChar(world->getSpecChar(mySpecies));

}

bool Organism::isAlive() { return alive; };

vec2d Organism::getPos() { return pos; }

int Organism::getStrenght() { return strenght; }

unsigned int Organism::getAge() { return age; }

void Organism::multiply()
{
	vec2d dir = world->getRandomFreePosAround(pos);
	if (!(dir == vec2d(0, 0)))
	{
		world->createOrganism(mySpecies, pos + dir);
	}
}
bool Organism::tryMultiply() { return true; }

bool Organism::blockTheAttack(Organism& org) { return false; }

bool Organism::dodge() { return false; }

void Organism::die() { 
	alive = false; 
	world->deleteOrganism(this);
}

Organism::~Organism()
{
}
