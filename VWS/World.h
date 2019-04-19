#pragma once
//#include"Organism.h"
//#include"Animal.h"
//#include"Wolf.h"

#include<vector>
#include<algorithm>
#include<ctime>
#include<map>
#include<string>
#include<cstdio>


enum species {
	FREE = 0,
	HUMAN = 1,
	WOLF = 2,
	SHEEP = 3,
	FOX = 4,
	TURTLE = 5,
	ANTELOPE = 6,
	CYBER_SHEEP = 7,
	GRASS = 8,
	DANDELION = 9,
	GUARANA = 10,
	DEADLY_BERRY = 11,
	SOS_HOGWEED = 12,
	ERR = 99
};

class Organism;
class Narrator;
class Human;

class vec2d {

public:
	int x, y;

	vec2d() {}
	vec2d(int x, int y) : x(x), y(y) {}
	vec2d(const vec2d& v) : x(v.x), y(v.y) {}

	vec2d operator+(const vec2d& v) {
		return vec2d(this->x + v.x, this->y + v.y);
	}

	vec2d& operator=(const vec2d& v)
	{
		vec2d tmp(v);
		std::swap(x, tmp.x);
		std::swap(y, tmp.y);
		return *this;
	}
};
bool operator==(const vec2d& v1, const vec2d& v2);


class World
{
private: 
	vec2d worldSize;
	std::vector<Organism*> organisms;
	bool exist;
	species**  worldboard;
	std::map<species, char> specChars;
	vec2d framepos;
	int randseed;

	void update();
	//void clearField();

public:

	Narrator& narrator;
	
	//World();
	World(FILE* file);
	World(vec2d worldSize,vec2d framepos);

	bool createOrganism(species spec, vec2d pos);
	void deleteOrganism(Organism* org);
	vec2d getRandomDirection();
	vec2d getRandomFreePosAround(vec2d pos);
	void nextRound();
	void draw()const;
	species getFieldSpecies(vec2d pos) const;
	vec2d getFramePos() const;
	vec2d getWorldSize() const;
	Organism* getOrganismOnPosition(vec2d pos)const;
	char getSpecChar(species sp);
	Human* getHuman()const;
	void saveBinary(FILE* file) const;
	bool loadOrganism(FILE* file);
	~World();
};

