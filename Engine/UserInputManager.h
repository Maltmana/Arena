#pragma once
#include "MainWindow.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Command.h"
class UserInputManager
{
public:
	UserInputManager(MainWindow & window);

	/*UserInputManager(const UserInputManager & userInputManager)
		:
		m_window{ userInputManager.m_window }
	{
		m_w = userInputManager.m_w;
		m_s = userInputManager.m_s;
		m_a = userInputManager.m_a;
		m_d = userInputManager.m_d;
	}


	UserInputManager(UserInputManager&& userInputManager) noexcept
		:
		m_window{ userInputManager.m_window }
	{
		numberOfUserInputManagers++;
	}

	UserInputManager & operator = (UserInputManager&& userInputManager) noexcept
	{
		numberOfUserInputManagers++;
		return *this;
	}*/

	Command * HandleInput();

	Keyboard & GetKeyboard();
	Mouse & GetMouse();


public:
	MainWindow & m_window;

	Command * m_W = 0;
	Command * m_S = 0;
	Command * m_A = 0;
	Command * m_D = 0;

	static LeftCommand leftCommand;
	static UpCommand upCommand;


	static int numberOfUserInputManagers;
};
