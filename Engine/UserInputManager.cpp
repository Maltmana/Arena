#include "UserInputManager.h"
#include <assert.h>
#include <vector>


UserInputManager::UserInputManager(MainWindow & window)
	:
	m_window{window}
{
	assert(numberOfUserInputManagers < 1);

	// TODO : have this command setter be linked to some kind of INI file or something

		m_W = &m_upCommand;	
		m_S = &m_downCommand;
		m_A = &m_leftCommand;
		m_D = &m_rightCommand;
		m_LClick = &m_createAtCursorCommand;
		numberOfUserInputManagers++;

}

std::vector<Command *> UserInputManager::HandleInput() // TODO : make it so that it responds to more than one button at once
{
	std::vector<Command *> commands;

	if (m_window.kbd.KeyIsPressed('W')) commands.push_back(m_W); // TODO : understand wtf this crazy thing is.
	if (m_window.kbd.KeyIsPressed('S')) commands.push_back(m_S);
	if (m_window.kbd.KeyIsPressed('A')) commands.push_back(m_A); // TODO : understand wtf this crazy thing is.
	if (m_window.kbd.KeyIsPressed('D')) commands.push_back(m_D);
	if (m_window.mouse.LeftIsReleased())
	{
		commands.push_back(m_LClick);
	}
	if (m_window.mouse.RightIsClickedOnce())
	{
		commands.push_back(m_LClick);
	}

	// nothing was pressed. do nothing.
	return commands;
}



Keyboard & UserInputManager::GetKeyboard()
{
	return m_window.kbd;
}

Mouse & UserInputManager::GetMouse()
{
	return m_window.mouse;
}

int UserInputManager::numberOfUserInputManagers = 0;

LeftCommand UserInputManager::m_leftCommand;
UpCommand UserInputManager::m_upCommand;
DownCommand UserInputManager::m_downCommand;
RightCommand UserInputManager::m_rightCommand;
CreateAtCursorCommand UserInputManager::m_createAtCursorCommand;
