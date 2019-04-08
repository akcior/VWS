#include "Animal.h"
#include"Plant.h"
#include<iostream>
#include"Narrator.h"



Animal::Animal(World* world, species sp, vec2d pos) : Organism(world, sp, pos)
{
	moveRange = 1;

}

bool Animal::strongerThan(Organism& o)
{
	if (this->strenght >= o.getStrenght()) return true;
	else return false;
}

bool Animal::collision(Organism& org) 
{
	if (dynamic_cast<Animal*>(&org) != nullptr)
	{
		if (mySpecies != org.mySpecies)
		{
			if (strongerThan(org))
			{
				if (!org.dodge())
				{

					if (!org.blockTheAttack(*this))
					{
						world->narrator.orgDieBecauseOfOrg(org.toString(), this->toString());
						org.die();
						return true;
					}

					return false;
				}

				return true;
			}
			else if (!this->blockTheAttack(org))
			{
				world->narrator.orgDieBecauseOfOrg(this->toString(), org.toString());
				alive = false;
				return false;
			}
		}
		else if(org.getAge() > 5)
		{
			if(tryMultiply())
				multiply();

			return false;
		}
	}
	else if (dynamic_cast<Plant*>(&org) != nullptr)
	{
		std::string orgname = org.toString();
		if (org.collision(*this)) {
			return true;
		}
		else
		{
			world->narrator.orgDieBecauseOfOrg(this->toString(), orgname);
			alive = false;
			return false;
		}

	}
	return false;
}

bool Animal::makeMove()
{
	vec2d dir;
	species field;
	do {
		dir = world->getRandomDirection();
		field = world->getFieldSpecies(pos + dir);
	} while (field == ERR);

	if (field == FREE)
	{
		pos = pos + dir;
		return true;
	}
	else
	{
		Organism* def = world->getOrganismOnPosition(pos + dir);
		if (collision(*def))
		{
			pos = pos + dir;
			return true;
		}
		else return false;
	}
}

bool Animal::action()
{
	//std::cout << "Wolf in action" << std::endl;;
	age++;
	if (alive && age > 1) {
		for (int i = 0; i < moveRange; i++)
		{
			if (!makeMove())
				break;
		}
	}
	if (!alive)
	{
		die();
		return false;
	}
	else return true;


}


Animal::~Animal()
{
}
