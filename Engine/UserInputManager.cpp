#include "UserInputManager.h"
#include <assert.h>

UserInputManager::UserInputManager(MainWindow & window)
	:
	m_window{window}
{
	assert(numberOfUserInputManagers < 1);
		LeftCommand a;
		m_a = &a;
		UpCommand w;
		m_w = &w;
		m_w->execute();

		numberOfUserInputManagers++;

}

void UserInputManager::HandleInput()
{
	if (m_window.kbd.KeyIsPressed(0x57))
	{
		m_w->execute();

	}
	if (m_window.kbd.KeyIsPressed(0x41))
	{
		m_a->execute(); // access violation during this operation when trying to access execute. must be something with the pointer creation.
	}
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
