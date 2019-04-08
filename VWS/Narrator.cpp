#include"Narrator.h"
#include"ConsolePrinter.h"
#include"Organism.h"

Narrator::Narrator(vec2d wrdframepos, vec2d wrdframesize)
{
	events.push_back("Hello everyone");
	dialogPos.x = wrdframepos.x + wrdframesize.x + 2;
	dialogPos.y = wrdframepos.y + wrdframesize.y / 2;
	dialogSize.x = ConsolePrinter::GetConsoleSize().x - dialogPos.x - 3;
}

Narrator::Narrator()
{

}

void Narrator::init(vec2d wrdframepos, vec2d wrdframesize)
{
	events.push_back("Hello everyone");
	dialogPos.x = wrdframepos.x + wrdframesize.x + 2;
	dialogPos.y = wrdframepos.y + wrdframesize.y / 2;
	dialogSize.x = ConsolePrinter::GetConsoleSize().x - dialogPos.x - 3;
}

void Narrator::orgDieBecauseOfOrg(std::string o1, std::string o2)
{
	events.push_back(o1 + " dies because of " + o2 + ".");
}

void Narrator::orgMultiply(std::string o)
{
	events.push_back(o + " has multiplicate.");
}

void Narrator::buff(Organism& o, bool inc, std::string name)
{
	std::string incdec;
	if (inc) incdec = "increased!";
	else incdec = "decreased!";
	events.push_back(o.toString() + " " + name + " has " + incdec);
}

void Narrator::powerUse(std::string o, std::string pwrname)
{
	events.push_back(o + " has use power: " + pwrname);
}

void Narrator::timeLeft(std::string desc, int left)
{
	events.push_back(desc + "is able for " + std::to_string(left) + "round");
}

void Narrator::narrate()
{
	dialogSize.y = events.size();
	int i = 0;
	ConsolePrinter::printFrame('#', dialogPos.x, dialogPos.y, dialogSize.x + 2, dialogSize.y + 2);
	for (std::string str : events)
	{
		ConsolePrinter::goToXY(dialogPos.x + 1, dialogPos.y + 1 + i);
		ConsolePrinter::writeString(&str[0]);
		i++;
	}
	events.clear();
}