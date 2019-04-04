#include "Plant.h"



Plant::Plant(World* world, species sp, vec2d pos) : Organism(world,sp, pos)
{
	initiative = 0;
	strenght = 0;
}
bool Plant::collision(Organism& an)
{
	this->die();
	return true;
}

void Plant::action() {

}

void Plant::multiply()
{

}
Plant::~Plant()
{
}
