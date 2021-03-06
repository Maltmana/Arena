#pragma once
#include "MainWindow.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Command.h"
class UserInputManager
{
public:
	UserInputManager(MainWindow & window);

	std::vector<Command *> HandleInput();

	Keyboard & GetKeyboard();
	Mouse & GetMouse();


public:
	MainWindow & m_window;

	Command * m_W = 0;
	Command * m_S = 0;
	Command * m_A = 0;
	Command * m_D = 0;
	Command * m_LClick = 0;
	Command * m_F5 = 0;

	

	//WARNING : 
	//In general, no.Need more information in order to ansewr for this specific case.In this specific case,
	//	I assume you're going through the-hell-that-is-pointers in order to remap keys at some later point?
	//	Is there a possibility of multiple instances of UserInputManager? If there are multiple UserInputManager, then your static solution may not work. 
	//	All UserInputManagers will start with the same keys and mess with each other's data.� user4581301 2 days ago
	static UpCommand m_upCommand;
	static DownCommand m_downCommand;
	static LeftCommand m_leftCommand;
	static RightCommand m_rightCommand;
	static CreateAtCursorCommand m_createAtCursorCommand;
	static QuickSaveCommand m_quickSaveCommand;



	static int numberOfUserInputManagers;
};
