#pragma once
#include "pch.h"
#include "GWO.h"


class CreatureCreator
{
public:

	// creates ogre uniqueptr and places on back of creatures vector
	// TODO : return the emplaced back creature so that you don't have to directly access the back of the vector to get to it!
	std::unique_ptr<GWO> CreateOgre()
	{
		std::vector<Vec2> const ogreModel = { { 20, -20 },{ 20,20 },{ -20,20 },{ -20,-20 } };

		return CreateCreature(Colors::Blue, ogreModel, "ogre");
	}
	// creates serp uniqueptr and places on back of creatures vector
	std::unique_ptr<GWO> CreateSerpent()
	{
		std::vector<Vec2> const serpentModel = { { 30, -10 },{ 30,10 },{ -30,10 },{ -30,-10 } };

		return CreateCreature(Colors::Green, serpentModel, "serpent");
	}
	// creates hum uniqueptr and places on back of creatures vector
	std::unique_ptr<GWO> CreateHuman()
	{
		std::vector<Vec2> const humanModel = { { 10, -10 },{ 10,10 },{ -10,10 },{ -10,-10 } };

		return CreateCreature(Colors::White, humanModel, "human");
	}

	std::unique_ptr<GWO> CreateCreature(Color const color, std::vector<Vec2> const hitbox, std::string const typeOf) const
	{
		return std::make_unique<GWO>("creature", std::make_unique<GraphicsComponent>(color), std::make_unique<InputComponent>(), std::make_unique<LogicComponent>(hitbox, typeOf));
	}
};