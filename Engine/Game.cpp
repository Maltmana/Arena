#include "Game.h"
#include "FileOutput.h"

Game::Game(Camera & camera, UserInputManager & userInputManager)
	:
	m_camera{ camera },
	m_userInputManager{userInputManager}
{
	//m_mainGWOContainer.emplace_back(m_camera); can't do it because a camera is not a unique ptr to GWO even though camera inherits from GWO. Not sure what to do without changing the GWO list.
}

void Game::BeginFrame()
{
	m_clock.frameTime = m_clock.GetCounterS(); // TODO ; simplify timer function to just be one call and the return is old time.
	m_clock.StartCounter();
}

void Game::UpdateInput()
{

}

void Game::UpdateController()
{
	GWO & controlledGWO = m_camera;

	double GWOSpeedMultByFrametime = controlledGWO.m_speed * m_clock.frameTime; // TEMP PUT THIS SOMEWHERE ELSE!!

	std::vector<Command *> commands = m_userInputManager.HandleInput();
	if (!commands.empty())
	{
		for (auto command : commands)
		{
			command->execute(m_creatureCreator, m_userInputManager.GetMouse(), controlledGWO, (float)GWOSpeedMultByFrametime, m_camera, m_fileOutput, m_mainGWOContainer);
		}
	}
}

void Game::UpdateModel()
{

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
	
void Game::UpdateOutput()
{
	// Graphics output
	if (m_drawHitboxMode)
	{
		for (auto & gwo : m_mainGWOContainer)
		{
			m_camera.DrawHitbox(*gwo);
		}
	}

	// File output
	m_fileOutput.Update(m_mainGWOContainer);
}

void Game::Go()
{
	m_camera.BeginFrame();
	BeginFrame();
	UpdateInput();
	UpdateController();
	UpdateModel();
	UpdateOutput();
	m_camera.EndFrame();
}