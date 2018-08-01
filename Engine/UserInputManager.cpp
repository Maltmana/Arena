#include "UserInputManager.h"
#include <assert.h>


UserInputManager::UserInputManager(MainWindow & window)
	:
	m_window{window}
{
	assert(numberOfUserInputManagers < 1);
		m_A = &leftCommand;
		m_W = &upCommand;	

		numberOfUserInputManagers++;

}

Command * UserInputManager::HandleInput()
{
	if (m_window.kbd.KeyIsPressed('W')) return  m_W; // TODO : understand wtf this crazy thing is.
	if (m_window.kbd.KeyIsPressed('A')) return  m_A;

	// nothing was pressed. do nothing.
	return NULL;
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
