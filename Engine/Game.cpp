#include "Game.h"

Game::Game(Camera & camera, UserInputManager & userInputManager)
	:
	m_camera{ camera },
	m_userInputManager{userInputManager}
{
	m_creatureHandler.MoveToContainer(m_creatureHandler.CreateHuman());
}

void Game::UpdateModel()
{

	// TODO : handle logic components.

	double frameTime = m_clock.GetCounterS();
	m_clock.StartCounter();
	GameWorldObject & activeGameWorldObject = m_camera;
	double speed = 100.f*frameTime;

	Command * command = m_userInputManager.HandleInput();
	if (command)
	{
		command->execute(activeGameWorldObject, (float)speed);
	}

/*
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			bool oldFollowC = m_followC;
			if (m_followC == false)
			{
				m_followC = true;
			}
			else
			{
				m_followC = false;
			}
			assert(!oldFollowC == m_followC);
		}

		if (m_followC)
		{
			m_camera.MoveTo(creatureManager.creatures.back().GetPos());
		}


		while (!wnd.mouse.IsEmpty())
		{
			const auto mr = wnd.mouse.Read();
			if (mr.GetType() == Mouse::Event::Type::WheelUp)
			{
				m_camera.SetScale(m_camera.GetScale() * 1.05f);
			}
			if (mr.GetType() == Mouse::Event::Type::WheelDown)
			{
				m_camera.SetScale(m_camera.GetScale() * 0.95f);
			}
		}

		if (wnd.kbd.KeyIsPressed(VK_CONTROL))
		{
			creatureManager.CreateCreature("human", m_camera.GetPos());
		}
		*/
}
	
void Game::ComposeFrame()
{


	// TODO : Handle graphics components.

	for (auto & c : m_creatureHandler.creatures)
	{
		c->GraphicsUpdate(m_camera);
	}

	/*ss.Update(m_camera);*/

	//const std::vector<Vec2> GUIrect = { {-200, -200}, { 0,0 } };
	//GameWorldObject GUI(GUIrect, camera.GetPos(), Colors::Magenta);

	//GUI.Update(camera);
}

void Game::Go()
{
	m_camera.BeginFrame();
	UpdateModel();
	ComposeFrame();
	m_camera.EndFrame();
}