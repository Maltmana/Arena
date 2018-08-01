#pragma once
#include <iostream>
#include "Camera.h"
#include "GameWorldObject.h"

/* Represents game actions. Uses Command pattern */
class Command
{
public:
	//virtual ~Command() {} // TODO : learn what this is
	virtual void execute(GameWorldObject & gameWorldObject, const float & offsetRate) = 0;
};

class UpCommand : public Command
{
public:
	virtual void execute(GameWorldObject & gameWorldObject, const float & offsetRate) override
	{
		gameWorldObject.MoveBy({ 0, offsetRate });
	}
	//virtual void execute() { MoveCameraUp(); }
};

class DownCommand : public Command
{
public:
	virtual void execute(GameWorldObject & gameWorldObject, const float & offsetRate) override
	{
		gameWorldObject.MoveBy({ 0, -offsetRate });
	}
};

class LeftCommand : public Command
{
public:
	virtual void execute(GameWorldObject & gameWorldObject, const float & offsetRate) override
	{
		gameWorldObject.MoveBy({-offsetRate, 0});
	}
};

class RightCommand : public Command
{
public:
	virtual void execute(GameWorldObject & gameWorldObject, const float & offsetRate) override
	{
		gameWorldObject.MoveBy({ offsetRate, 0 });
	}
};

class NullCommand : public Command
{
public:
	//virtual void execute() override { }
};


