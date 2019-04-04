#include "Animal.h"
#include"Plant.h"
#include<iostream>



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

					if (!org.blockTheAttack())
					{
						org.die();
						return true;
					}

					return false;
				}

				return true;
			}
			else if (!this->blockTheAttack())
			{
				die();
				return false;
			}
		}
		else if(org.getAge() > 5)
		{
			multiply();
			return false;
		}
	}
	else if (dynamic_cast<Plant*>(&org) != nullptr)
	{
		if (org.collision(*this)) {
			return true;
		}
	}
	return false;
}

void Animal::multiply()
{
	vec2d dir;
	species field;
	bool freefield = false;
	for (int i = -1; i < 2 && !freefield; i++)
	{
		for (int j = -1; j < 2 && !freefield; j++)
		{
			if (world->getFieldSpecies(pos + vec2d(i, j)) == FREE) freefield = true;
		}
	}
	if (freefield)
	{
		do {
			dir = World::getRandomDirection();
			field = world->getFieldSpecies(pos + dir);
		} while (field != FREE);
		world->createOrganism(mySpecies, pos + dir);
	}
}

bool Animal::makeMove()
{
	vec2d dir;
	species field;
	do {
		dir = World::getRandomDirection();
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

void Animal::action()
{
	std::cout << "Wolf in action" << std::endl;;
	age++;
	if (alive && age > 1) {
		for (int i = 0; i < moveRange; i++)
		{
			if (!makeMove())
				break;
		}
	}


}


Animal::~Animal()
{
}
