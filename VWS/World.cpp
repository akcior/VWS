#include "World.h"
#include"Organisms.h"
#include"ConsolePrinter.h"
#include"Narrator.h"
#include<algorithm>

bool operator==(const vec2d& v1, const vec2d& v2)
{
	return v1.x == v2.x && v1.y == v2.y;
}

World::World(vec2d worldsize, vec2d framepos) : worldSize(worldsize), framepos(framepos), narrator(*new Narrator(framepos, worldsize))
{
	worldboard = new species*[worldsize.x];
	for (int i = 0; i < worldsize.x; i++)
	{
		worldboard[i] = new species[worldsize.y];
		for (int j = 0; j < worldsize.y; j++)
		{
			worldboard[i][j] = FREE;
		}

	}
	exist = true;
	randseed = 1253354233;
	srand(randseed);

	createOrganism(WOLF, vec2d(1, 5));
	createOrganism(SHEEP, vec2d(10, 1));
	createOrganism(SHEEP, vec2d(10, 7));
	createOrganism(FOX, vec2d(11, 11));
	createOrganism(GRASS, vec2d(10, 10));
	createOrganism(ANTELOPE, vec2d(6, 7));
	createOrganism(TURTLE, vec2d(9, 4));
	createOrganism(HUMAN, vec2d(9, 9));
	createOrganism(GUARANA, vec2d(8, 8));
	createOrganism(DEADLY_BERRY, vec2d(7, 7));
	createOrganism(SOS_HOGWEED, vec2d(5, 5));

	specChars = {
	{HUMAN, '$' },
	{WOLF, 'W'},
	{SHEEP, 'S'},
	{FOX, 'F'},
	{TURTLE, 'T'},
	{ANTELOPE, 'A'},
	{CYBER_SHEEP, 'C'},
	{GRASS, 'G'},
	{DANDELION, 'D'},
	{GUARANA, 'U'},
	{DEADLY_BERRY, 'E'},
	{SOS_HOGWEED, 'H'}
	};

}

World::World(FILE* file) :narrator(*new Narrator())
{

	fread(&worldSize, sizeof(vec2d), 1, file);


	worldboard = new species*[worldSize.x];
	for (int i = 0; i < worldSize.x; i++)
	{
		worldboard[i] = new species[worldSize.y];
		for (int j = 0; j < worldSize.y; j++)
		{
			worldboard[i][j] = FREE;
		}

	}

	fread(&framepos, sizeof(vec2d), 1, file);

	narrator.init(framepos, worldSize);

	fread(&randseed, sizeof(int), 1, file);
	while (!feof(file))
	{
		loadOrganism(file);
	}

	exist = true;
	srand(randseed);

	specChars = {
	{HUMAN, '$' },
	{WOLF, 'W'},
	{SHEEP, 'S'},
	{FOX, 'F'},
	{TURTLE, 'T'},
	{ANTELOPE, 'A'},
	{CYBER_SHEEP, 'C'},
	{GRASS, 'G'},
	{DANDELION, 'D'},
	{GUARANA, 'U'},
	{DEADLY_BERRY, 'E'},
	{SOS_HOGWEED, 'H'}
	};
}

bool World::createOrganism(species sp, vec2d pos)
{
	Organism* org;
	switch (sp)
	{
	case HUMAN:
		org = new Human(this, pos);
		break;
	case WOLF:
		org = new Wolf(this, pos);
		break;
	case SHEEP:
		org = new Sheep(this, pos);
		break;
	case FOX:
		org = new Fox(this, pos);
		break;
	case TURTLE:
		org = new Turtle(this, pos);
		break;
	case ANTELOPE:
		org = new Antelope(this, pos);
		break;
	case CYBER_SHEEP:
		//todo
		break;
	case GRASS:
		org = new Grass(this, pos);
		break;
	case DANDELION:
		org = new Dandelion(this, pos);
		break;
	case GUARANA:
		org = new Guarana(this, pos);
		break;
	case DEADLY_BERRY:
		org = new Deadly_berry(this, pos);
		break;
	case SOS_HOGWEED:
		org = new Sos_hogweed(this, pos);
		break;
	default :
		return false;
	}
	organisms.push_back(org);
	worldboard[org->getPos().x][org->getPos().y] = org->mySpecies;
	return true;
}

bool World::loadOrganism(FILE* file)
{
	species sp;
	Organism* org;

	fread(&sp, sizeof(species), 1, file);

	switch (sp)
	{
	case HUMAN:
		org = new Human(this, file);
		break;
	case WOLF:
		org = new Wolf(this, file);
		break;
	case SHEEP:
		org = new Sheep(this, file);
		break;
	case FOX:
		org = new Fox(this, file);
		break;
	case TURTLE:
		org = new Turtle(this, file);
		break;
	case ANTELOPE:
		org = new Antelope(this, file);
		break;
	case CYBER_SHEEP:
		//todo
		break;
	case GRASS:
		org = new Grass(this, file);
		break;
	case DANDELION:
		org = new Dandelion(this, file);
		break;
	case GUARANA:
		org = new Guarana(this, file);
		break;
	case DEADLY_BERRY:
		org = new Deadly_berry(this, file);
		break;
	case SOS_HOGWEED:
		org = new Sos_hogweed(this, file);
		break;
	default:
		return false;
	}
	organisms.push_back(org);
	worldboard[org->getPos().x][org->getPos().y] = org->mySpecies;
	return true;
}


void World::deleteOrganism(Organism* org)
{
	std::vector<Organism*>::iterator p;
	p = std::find(organisms.begin(), organisms.end(), org);
	organisms.erase(p);
	worldboard[org->getPos().x][org->getPos().y] = FREE;
	delete org;

}

vec2d World::getRandomDirection()
{
	//static unsigned int seed = 234235;
	srand(randseed);
	int d = rand() % 4;
	static vec2d dir;
	switch (d) {
	case 0:
		dir.x = 0;
		dir.y = -1;
		break;
	case 1:
		dir.x = 1;
		dir.y = 0;
		break;
	case 2:
		dir.x = 0;
		dir.y = 1;
		break;
	case 3:
		dir.x = -1;
		dir.y = 0;
		break;
	}
	randseed += time(NULL) % 31;
	randseed %= 42792384;
	return dir;
}

vec2d World::getRandomFreePosAround(vec2d pos)
{
	std::vector<vec2d> dir;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2 ; j++)
		{
			if (getFieldSpecies(pos + vec2d(i, j)) == FREE) dir.push_back(vec2d(i,j));
		}
	}
	if (dir.size() > 0)
	{
		int i = rand() % dir.size();
		return dir[i];
	}
	else return vec2d(0, 0); // dir == vec2d(0,0) means that there is no free field around that pos
}

void World::update()
{
	/*for (int i = 0; i < worldSize.x; i++)
	{
		for (int j = 0; j < worldSize.y; j++)
		{
			worldboard[i][j] = FREE;
		}
	}*/

	std::vector<Organism*>::iterator p;
	//p = organisms.begin();
	//vec2d orgpos;
	for (Organism* o : organisms)
	{
		if (!o->isAlive())
		{
			p = std::find(organisms.begin(), organisms.end(), o);
			organisms.erase(p);
			//worldboard[o->getPos().x][o->getPos().y] = FREE;
			delete o;
		}
		/*else
		{
			orgpos = o->getPos();
			worldboard[orgpos.x][orgpos.y] = o->mySpecies;
		}*/
		//if(p < organisms.end())p++;
	}
}

void World::nextRound()
{
	//update();
	std::sort(organisms.begin(), organisms.end(), Organism::cmpPrt);
	std::reverse(organisms.begin(), organisms.end());
	vec2d prevpos;
	size_t p = 0;
	Organism* o;
	while (p < organisms.size())
	{
		o = organisms[p];
		prevpos = o->getPos();
			if (o->action()) // if true organism is alive after action
			{
				if (!(prevpos == o->getPos())) // check if organism make move
				{
					worldboard[prevpos.x][prevpos.y] = FREE;
					worldboard[o->getPos().x][o->getPos().y] = o->mySpecies;
				}
			}
		p++;
	}
}
void World::draw()
{
	for (Organism* o : organisms)
	{
		o->draw();
	}

	narrator.narrate();
	//test
	/*for (int i = 0; i < worldSize.x; i++)
	{
		for (int j = 0; j < worldSize.y; j++)
		{
			ConsolePrinter::goToXY(23 + i,1 + j);
			ConsolePrinter::writeChar(specChars[worldboard[i][j]]);
		}
	}*/
}

species World::getFieldSpecies(vec2d pos)
{
	if (pos.x >= 0 && pos.y >= 0 &&
		pos.x < worldSize.x && pos.y < worldSize.y) {
		return worldboard[pos.x][pos.y];
	}
	
	return ERR;
}

Organism* World::getOrganismOnPosition(vec2d pos)
{
	for (Organism* o : organisms)
	{
		if (pos == o->getPos()) return o;
	}
	return NULL;
}

Human* World::getHuman()
{
	for (Organism* o : organisms)
	{
		if (o->mySpecies == HUMAN) return dynamic_cast<Human*>(o);
	}
	return nullptr;
}

vec2d World::getFramePos()
{
	return framepos;
}

vec2d World::getWorldSize()
{
	return worldSize;
}

char World::getSpecChar(species sp)
{
	return specChars[sp];
}

void World::saveBinary(FILE* file)
{
	fwrite(&worldSize, sizeof(vec2d), 1, file);
	fwrite(&framepos, sizeof(vec2d), 1, file);
	fwrite(&randseed, sizeof(int), 1, file);
	for (Organism* o : organisms)
	{
		o->saveBinary(file);
	}
}

World::~World()
{
	for (Organism* o : organisms)
	{
		delete o;
	}

	organisms.clear();
	for(int i =0 ; i < worldSize.x;i++)
	{
		delete[] worldboard[i];
	}
	delete[] worldboard;
}
