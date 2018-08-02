#pragma once
#include <string>
#include "Vec2.h"
#include "GameWorldObject.h"

class CreatureHandler
{
public:

	// these create specialized objects with special components that define the creature made

	GameWorldObject & CreateOgre()
	{
		std::vector<Vec2> ogreModel = { { 20, -20 },{ 20,20 },{ -20,20 },{ -20,-20 } };

		return 	creatures.emplace_back(CreateCreature(Colors::Blue, ogreModel));
	}
	GameWorldObject & CreateSerpent()
	{
		std::vector<Vec2> serpentModel = { { 30, -10 },{ 30,10 },{ -30,10 },{ -30,-10 } };
		return creatures.emplace_back(CreateCreature(Colors::Green, serpentModel));
	}
	GameWorldObject & CreateHuman()
	{
		std::vector<Vec2> humanModel = { { 10, -10 },{ 10,10 },{ -10,10 },{ -10,-10 } };
		return creatures.emplace_back(CreateCreature(Colors::White, humanModel));
	}

	GameWorldObject * CreateCreature(const Color & color, std::vector<Vec2> hitbox)
	{

		return new GameWorldObject(new GraphicsComponent(color), new InputComponent(), new LogicComponent(hitbox));

	}



	std::vector<GameWorldObject> creatures;
};