#pragma once
#include"World.h"


//class vec2d;

class Organism
{
protected:
	int strenght;
	int initiative;
	vec2d pos;
	World* world;
	bool alive;
	unsigned int age;

	friend bool operator<(const Organism& o1, Organism& o2)
	{
		if (o1.initiative == o2.initiative) return o1.age < o2.age;
		else return o1.initiative < o2.initiative;
	}

public:
	Organism(World* world, species sp, vec2d pos);
	const species mySpecies;
	virtual void action() = 0;
	virtual bool collision(Organism& org)=0;
	virtual void draw();
	virtual bool isAlive();
	virtual vec2d getPos();
	virtual int getStrenght();
	virtual unsigned int getAge();
	virtual void multiply();
	virtual bool tryMultiply();
	virtual bool blockTheAttack();
	virtual bool dodge();
	virtual void die();
	~Organism();
};

