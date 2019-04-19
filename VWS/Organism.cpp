#include "Organism.h"
#include "ConsolePrinter.h"
#include "Narrator.h"
#include <map>


Organism::Organism(World* world, species sp, vec2d pos): mySpecies(sp), world(world), pos(pos)
{
	alive = true;
	age = 0;
}

Organism::Organism(World* world, species sp, FILE* file) : mySpecies(sp), world(world)
{
	fread(&strenght, sizeof(int), 1, file);
	fread(&initiative, sizeof(int), 1, file);
	fread(&pos, sizeof(vec2d), 1, file);
	fread(&age, sizeof(unsigned int), 1, file);
	alive = true;
}

void Organism::draw() const 
{

	vec2d drawPos = world->getFramePos() + pos + vec2d(1, 1);
	ConsolePrinter::goToXY(drawPos.x, drawPos.y);
	ConsolePrinter::writeChar(world->getSpecChar(mySpecies));

}

bool Organism::isAlive() const { return alive; };

vec2d Organism::getPos() const { return pos; }

int Organism::getStrenght() const { return strenght; }

void Organism::addStrenght(int st)
{
	strenght += st;
	world->narrator.buff(*this, st >= 0, "strenght");
}

unsigned int Organism::getAge() const { return age; }

void Organism::multiply()
{
	vec2d dir = world->getRandomFreePosAround(pos);
	if (!(dir == vec2d(0, 0)))
	{
		world->narrator.orgMultiply(this->toString());
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

void Organism::saveBinary(FILE* file) const
{
	fwrite(&mySpecies, sizeof(species), 1, file);
	fwrite(&strenght, sizeof(int), 1, file);
	fwrite(&initiative, sizeof(int), 1, file);
	fwrite(&pos, sizeof(vec2d), 1, file);
	fwrite(&age, sizeof(unsigned int), 1, file);
}

bool Organism::cmpPrt(Organism* o1, Organism* o2)
{
	if (o1->initiative == o2->initiative) return o1->age < o2->age;
	else return o1->initiative < o2->initiative;
}

Organism::~Organism()
{
}
