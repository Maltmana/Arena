#pragma once
#include "pch.h"
#include "GameWorldObject.h"


class CreatureHandler
{
public:

	// these create specialized objects with special components that define the creature made

	std::unique_ptr<GameWorldObject> CreateOgre() const
	{
		std::vector<Vec2> const ogreModel = { { 20, -20 },{ 20,20 },{ -20,20 },{ -20,-20 } };

		return CreateCreature(Colors::Blue, ogreModel, "ogre");
	}
	std::unique_ptr<GameWorldObject> CreateSerpent() const
	{
		std::vector<Vec2> const serpentModel = { { 30, -10 },{ 30,10 },{ -30,10 },{ -30,-10 } };

		return CreateCreature(Colors::Green, serpentModel, "serpent");
	}
	std::unique_ptr<GameWorldObject> CreateHuman() const
	{
		std::vector<Vec2> const humanModel = { { 10, -10 },{ 10,10 },{ -10,10 },{ -10,-10 } };

		return CreateCreature(Colors::White, humanModel, "human");
	}

	std::unique_ptr<GameWorldObject> CreateCreature(Color const color, std::vector<Vec2> const hitbox, std::string const typeOf) const
	{
		return std::make_unique<GameWorldObject>(std::make_unique<GraphicsComponent>((Colors::Green), std::make_unique<InputComponent>(), std::make_unique<LogicComponent>(hitbox, typeOf)));
	}

	std::unique_ptr<GameWorldObject> MoveToContainer(std::unique_ptr<GameWorldObject> creature)
	{
		creatures.emplace_back(std::move(creature));
		assert(creature);
	}

	std::vector<GameWorldObject> creatures;
};