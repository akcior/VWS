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

public:
	Organism(World* world, species sp, FILE* file);
	Organism(World* world, species sp, vec2d pos);
	const species mySpecies;
	virtual bool action() = 0;
	virtual bool collision(Organism& org)=0;
	virtual void draw() const;
	virtual bool isAlive() const;
	virtual vec2d getPos() const;
	virtual int getStrenght() const;
	virtual void addStrenght(int st);
	virtual unsigned int getAge() const;
	virtual void multiply();
	virtual bool tryMultiply();
	virtual bool blockTheAttack(Organism& org);
	virtual bool dodge();
	virtual void die();
	virtual void saveBinary(FILE* file) const;
	virtual std::string toString() =0;

	static bool cmpPrt(Organism* o1, Organism* o2);
	~Organism();
};

