#include "Organism.h"
#include "ConsolePrinter.h"
#include<map>


Organism::Organism(World* world, species sp, vec2d pos): mySpecies(sp), world(world), pos(pos)
{
	alive = true;
	age = 1;
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

bool Organism::tryMultiply() { return true; }

bool Organism::blockTheAttack() { return false; }

bool Organism::dodge() { return false; }

void Organism::die() { alive = false; }

Organism::~Organism()
{
}
