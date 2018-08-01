#pragma once
#include <iostream>

/* Represents game actions. Uses Command pattern */
class Command
{
public:
	//virtual ~Command() {} // TODO : learn what this is
	virtual void execute() = 0;
};

class UpCommand : public Command
{
public:
	virtual void execute()
	{
		executionN++;
	}
	int executionN = 0;
	//virtual void execute() { MoveCameraUp(); }
};

class DownCommand : public Command
{
public:
	//virtual void execute() { MoveCameraDown(); }
};

class LeftCommand : public Command
{
public:
	virtual void execute()
	{
		executionN++;
	}
	int executionN = 0;
};

class RightCommand : public Command
{
public:
	//virtual void execute() { MoveCameraRight(); }
};

class NullCommand : public Command
{
public:
	virtual void execute() { }
};


