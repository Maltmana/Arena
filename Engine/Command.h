#pragma once
#include <iostream>
#include "Camera.h"
#include "GWO.h"
#include "CreatureHandler.h"
#include "Mouse.h"
#include "GameMath.h"

#define EXECUTEPARAM CreatureHandler & creatureHandler, Mouse & mouse, GWO & gWO, const float & offsetRate, Camera const & camera

/* Represents game actions. Uses Command pattern */
class Command
{
public:
	//virtual ~Command() {} // TODO : learn what this is
	virtual void execute(EXECUTEPARAM) = 0;
};

class UpCommand : public Command
{
public:
	virtual void execute(EXECUTEPARAM) override
	{
		gWO.m_position += { 0, offsetRate };
	}
	//virtual void execute() { MoveCameraUp(); }
};

class DownCommand : public Command
{
public:
	virtual void execute(EXECUTEPARAM) override
	{
		gWO.m_position += { 0, -offsetRate };
	}
};

class LeftCommand : public Command
{
public:
	virtual void execute(EXECUTEPARAM) override
	{
		gWO.m_position += {-offsetRate, 0};
	}
};

class RightCommand : public Command
{
public:
	virtual void execute(EXECUTEPARAM) override
	{
		gWO.m_position += { offsetRate, 0 };
	}
};

class CreateAtCursorCommand : public Command
{
public:
	virtual void execute(EXECUTEPARAM) override
	{
		creatureHandler.CreateHuman(); // TODO : have both these lines in one? if CreateHuman returns reference to the creature just emplaced.
		creatureHandler.creatures.back().get()->m_position = GameMath::WindowCoordinatesToGameWorldCoordinates((Vec2)mouse.GetPos(),camera); // TODO ; is casting appropriate here?
			
	}
};

class NullCommand : public Command
{
public:
	//virtual void execute() override { }
};


