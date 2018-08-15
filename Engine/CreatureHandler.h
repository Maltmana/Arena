#pragma once
#include "pch.h"
#include "GO.h"
#include "Colors.h"


class CreatureHandler
{
public:

	// these create specialized objects with special components that define the creature made

	std::unique_ptr<GO> CreateOgre() const
	{
		std::vector<Vec2> const ogreModel = { { 20, -20 },{ 20,20 },{ -20,20 },{ -20,-20 } };

		return CreateCreature(Colors::Blue, ogreModel, "ogre");
	}
	std::unique_ptr<GO> CreateSerpent() const
	{
		std::vector<Vec2> const serpentModel = { { 30, -10 },{ 30,10 },{ -30,10 },{ -30,-10 } };

		return CreateCreature(Colors::Green, serpentModel, "serpent");
	}
	std::unique_ptr<GO> CreateHuman() const
	{
		std::vector<Vec2> const humanModel = { { 10, -10 },{ 10,10 },{ -10,10 },{ -10,-10 } };

		return CreateCreature(Colors::White, humanModel, "human");
	}

	std::unique_ptr<GO> CreateCreature(Color const color, std::vector<Vec2> const hitbox, std::string const typeOf) const
	{
		return std::make_unique<GO>(std::make_unique<GraphicsComponent>(color), std::make_unique<InputComponent>(), std::make_unique<LogicComponent>(hitbox, typeOf));
	}

	// calls std::move on parameter and asserts that parameter is now null
	void MoveToContainer(std::unique_ptr<GO> creature)
	{
		creatures.push_back(std::move(creature));
		assert(!creature);
	}

	std::vector<std::unique_ptr<GO>> creatures;
};