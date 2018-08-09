#include "UserInputManager.h"
#include <assert.h>
#include <vector>


UserInputManager::UserInputManager(MainWindow & window)
	:
	m_window{window}
{
	assert(numberOfUserInputManagers < 1);

		m_W = &upCommand;	
		m_S = &downCommand;
		m_A = &leftCommand;
		m_D = &rightCommand;
		numberOfUserInputManagers++;

}

std::vector<Command *> UserInputManager::HandleInput() // TODO : make it so that it responds to more than one button at once
{
	std::vector<Command *> commands;

	if (m_window.kbd.KeyIsPressed('W')) commands.push_back(m_W); // TODO : understand wtf this crazy thing is.
	if (m_window.kbd.KeyIsPressed('S')) commands.push_back(m_S);
	if (m_window.kbd.KeyIsPressed('A')) commands.push_back(m_A); // TODO : understand wtf this crazy thing is.
	if (m_window.kbd.KeyIsPressed('D')) commands.push_back(m_D);

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

LeftCommand UserInputManager::leftCommand;
UpCommand UserInputManager::upCommand;
DownCommand UserInputManager::downCommand;
RightCommand UserInputManager::rightCommand;
