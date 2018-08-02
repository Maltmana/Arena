#pragma once
#include <string>
#include "Vec2.h"
#include "GameWorldObject.h"

class CreatureHandler
{
public:

	// these create specialized objects with special components that define the creature made

	GameWorldObject CreateOgre()
	{
		std::vector<Vec2> ogreModel = { { 20, -20 },{ 20,20 },{ -20,20 },{ -20,-20 } };

		GameWorldObject ogre{ CreateCreature(Colors::Blue, ogreModel) };

		return 	creatures.emplace_back(ogre);
	}
	GameWorldObject CreateSerpent()
	{
		std::vector<Vec2> serpentModel = { { 30, -10 },{ 30,10 },{ -30,10 },{ -30,-10 } };

		GameWorldObject serpent{ CreateCreature(Colors::Green, serpentModel) };

		return creatures.emplace_back(serpent);
	}
	GameWorldObject CreateHuman()
	{
		std::vector<Vec2> humanModel = { { 10, -10 },{ 10,10 },{ -10,10 },{ -10,-10 } };

		GameWorldObject human{ CreateCreature(Colors::White, humanModel) };

		return creatures.emplace_back(human);
	}

	GameWorldObject & CreateCreature(const Color & color, std::vector<Vec2> hitbox)
	{

		return GameWorldObject(new GraphicsComponent(Colors::Green), new InputComponent(), new LogicComponent(hitbox));

	}

	std::vector<GameWorldObject> creatures;
};