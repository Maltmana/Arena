#pragma once
#include <iostream>
#include "Camera.h"
#include "GWO.h"

/* Represents game actions. Uses Command pattern */
class Command
{
public:
	//virtual ~Command() {} // TODO : learn what this is
	virtual void execute(GWO & gWO, const float & offsetRate) = 0;
};

class UpCommand : public Command
{
public:
	virtual void execute(GWO & gWO, const float & offsetRate) override
	{
		gWO.m_position += { 0, offsetRate };
	}
	//virtual void execute() { MoveCameraUp(); }
};

class DownCommand : public Command
{
public:
	virtual void execute(GWO & gWO, const float & offsetRate) override
	{
		gWO.m_position += { 0, -offsetRate };
	}
};

class LeftCommand : public Command
{
public:
	virtual void execute(GWO & gWO, const float & offsetRate) override
	{
		gWO.m_position += {-offsetRate, 0};
	}
};

class RightCommand : public Command
{
public:
	virtual void execute(GWO & gWO, const float & offsetRate) override
	{
		gWO.m_position += { offsetRate, 0 };
	}
};

class NullCommand : public Command
{
public:
	//virtual void execute() override { }
};


