#include"Turtle.h"

Turtle::Turtle(World* world, vec2d pos) : Animal(world, TURTLE, pos)
{
	initiative = 1;
	strenght = 2;
}

Turtle::Turtle(World* world, FILE* file) : Animal(world, TURTLE, file)
{

}

bool Turtle::blockTheAttack(Organism& org)
{
	if (org.getStrenght() < 5) return true;

	return false;
}

bool Turtle::action()
{
	if (rand() % 100 < 25) return Animal::action();
	else return true;
}

std::string Turtle::toString()
{
	return ("Turtle on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}