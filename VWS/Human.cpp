#include "Human.h"
#include"Narrator.h"

Human::Human(World* world, vec2d pos) : Animal(world, HUMAN, pos)
{
	initiative = 4;
	strenght = 5;
	nextmove = vec2d(0, 0);
	powerinterval = 5;
	poweractive = false;
	powerdelay = 99;
}

Human::Human(World* world, FILE* file) : Animal(world, HUMAN, file)
{
	fread(&nextmove, sizeof(vec2d), 1, file);
	fread(&powertime, sizeof(int), 1, file);
	fread(&powerinterval, sizeof(int), 1, file);
	fread(&powerdelay, sizeof(int), 1, file);
	fread(&poweractive, sizeof(bool), 1, file);

}

void Human::draw()
{

	Organism::draw();
}
bool Human::tryMultiply()
{
	return false;
}
bool Human::setNextMove(vec2d dir)
{
	if (world->getFieldSpecies(pos + dir) != ERR)
	{
		nextmove = dir;
		return true;
	}
	else return false;

}
bool Human::action()
{
	bool ex;
	if (world->getFieldSpecies(pos + nextmove) == ERR) nextmove = vec2d(0, 0);
	if (!(nextmove == vec2d(0, 0))) ex = Animal::action();
	else
	{
		age++;
		ex = true;
	}

	if (poweractive && ex)
	{
		species field;
		Organism* org;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				field = world->getFieldSpecies(pos + vec2d(i, j));
				if (field != FREE && field != ERR && !(i == nextmove.x*(-1) && j == nextmove.y*(-1)))
				{
					org = world->getOrganismOnPosition(pos + vec2d(i, j));
					world->narrator.orgDieBecauseOfOrg(org->toString(), this->toString());
					org->die();
				}
			}
		}
		powertime++;
		world->narrator.timeLeft("Fire floor ", powerinterval - powertime);
		if (powertime >= powerinterval) poweractive = false;
	}
	else {
		powerdelay++;
	}

	return ex;
}

bool Human::makeMove()
{
	species field = world->getFieldSpecies(pos + nextmove);

	if (field == FREE)
	{
		pos = pos + nextmove;
		return true;
	}
	else
	{
		Organism* def = world->getOrganismOnPosition(pos + nextmove);
		if (collision(*def))
		{
			pos = pos + nextmove;
			return true;
		}
		else return false;
	}
}

vec2d Human::getNextMove()
{
	return nextmove;
}

int Human::useSuperPower()
{
	if (!poweractive && powerdelay > powerinterval)
	{
		poweractive = true;
		powerdelay = 0;
		powertime = 0;
		world->narrator.powerUse(this->toString(), "Fire floor");
		world->narrator.timeLeft("Fire floor", powerinterval - powertime);
	}
	return powerdelay;
}

std::string Human::toString()
{
	return "Human on position X: " + std::to_string(pos.x) + " ,Y: " + std::to_string(pos.y);
}

void Human::saveBinary(FILE* file)
{
	Animal::saveBinary(file);
	fwrite(&nextmove, sizeof(vec2d), 1, file);
	fwrite(&powertime, sizeof(int), 1, file);
	fwrite(&powerinterval, sizeof(int), 1, file);
	fwrite(&powerdelay, sizeof(int), 1, file);
	fwrite(&poweractive, sizeof(bool), 1, file);
}