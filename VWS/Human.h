#pragma once
#include "Animal.h"

class Human :
	public Animal
{
private:
	vec2d nextmove;
	int powertime;
	int powerinterval;
	int powerdelay;
	bool poweractive;
public:
	Human(World* world, FILE* file);
	Human(World* world, vec2d pos);

	void draw() const override;
	bool setNextMove(vec2d dir);
	std::string toString() override;
	bool action() override;
	bool tryMultiply() override;
	bool makeMove() override;
	int useSuperPower();
	vec2d getNextMove();
	void saveBinary(FILE* file) const override;

};