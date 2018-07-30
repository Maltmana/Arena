#include "CreatureManager.h"

Creature CreatureManager::CreateCreature(std::string type, Vec2 position)
{

	std::vector<Vec2> humanModel = { { 10, -10 },{ 10,10 },{ -10,10 },{ -10,-10 } }; // TODO : Get the creature from a txt file which contains json creature templates.
	Creature c{ humanModel, "human", 50, 10.f, position, Colors::Red };
	creatures.emplace_back(c);
	return c;
}

Creature CreatureManager::AddCreature(Creature & creature)
{
	creatures.emplace_back(creature);
	return creature;
}
