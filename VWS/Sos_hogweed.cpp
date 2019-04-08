#include"Sos_hogweed.h"
#include"Narrator.h"

Sos_hogweed::Sos_hogweed(World* world, vec2d pos) : Plant(world, SOS_HOGWEED, pos)
{
	strenght = 10;
}

bool Sos_hogweed::action()
{
	species field;
	Organism* org;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			field = world->getFieldSpecies(pos + vec2d(i,j));
			if (field != FREE && field != ERR && (i !=0 && j != 0))
			{
				org = world->getOrganismOnPosition(pos + vec2d(i, j));
				if (org->mySpecies != CYBER_SHEEP && org->mySpecies != SOS_HOGWEED)
				{
					world->narrator.orgDieBecauseOfOrg(org->toString(), this->toString());
					org->die();
				}
			}
		}
	}
	return Plant::action();
}

bool Sos_hogweed::collision(Organism& org)
{
	//world->narrator.orgDieBecauseOfOrg(*this, org);
	//this->die();
	return false;
}

std::string Sos_hogweed::toString()
{
	return ("Sosnowsky's hogweed on position X:" + std::to_string(pos.x) + ", Y:" + std::to_string(pos.y));
}