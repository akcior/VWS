#include"Narrator.h"
#include"ConsolePrinter.h"
#include"Organism.h"

Narrator::Narrator(vec2d wrdframepos, vec2d wrdframesize)
{
	events.push_back("Helo everyone");
	dialogPos.x = wrdframepos.x + wrdframesize.x + 2;
	dialogPos.y = wrdframepos.y + wrdframesize.y / 2;
	dialogSize.x = ConsolePrinter::GetConsoleSize().x - dialogPos.x - 3;
	//dialogSize.y = ConsolePrinter::GetConsoleSize().y - dialogPos.y - 1;
}

void Narrator::orgDieBecauseOfOrg(Organism& o1, Organism& o2)
{
	events.push_back(o1.toString() + " dies because of " + o2.toString() + ".");
}

void Narrator::orgMultiply(Organism& o)
{
	events.push_back(o.toString() + " has multiplicate.");
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