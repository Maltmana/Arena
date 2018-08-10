#pragma once
#include <iostream>
#include "Camera.h"
#include "GWO.h"
#include "CreatureHandler.h"
#include "Mouse.h"

#define EXECUTEPARAM CreatureHandler & creatureHandler, Mouse & mouse, GWO & gWO, const float & offsetRate

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
	
		creatureHandler.CreateHuman();
		creatureHandler.creatures.back().get()->m_position = { (float)mouse.GetPosX(), (float)mouse.GetPosY() * -1.f }; // TODO ; is casting appropriate here?
			
	}
};

class NullCommand : public Command
{
public:
	//virtual void execute() override { }
};


