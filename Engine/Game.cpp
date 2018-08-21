#include "Game.h"
#include "FileIO.h"

Game::Game(Camera & camera, UserInputManager & userInputManager)
	:
	m_camera{ camera },
	m_userInputManager{userInputManager}
{
	m_MainGWOContainer.emplace_back(m_creatureCreator.CreateOgre()); // TEMP TEST
}

void Game::BeginFrame()
{

	m_clock.frameTime = m_clock.GetCounterS(); // TODO ; simplify timer function to just be one call and the return is old time.
	m_clock.StartCounter();
}

void Game::UpdateInput()
{

	// m_fileInput.update();

}

void Game::UpdateController()
{
	GWO & controlledGWO = m_camera;

	double GWOSpeedMultByFrametime = controlledGWO.speed * m_clock.frameTime; // TEMP PUT THIS SOMEWHERE ELSE!!

	std::vector<Command *> commands = m_userInputManager.HandleInput();
	if (!commands.empty())
	{
		for (auto command : commands)
		{
			command->execute(m_creatureCreator, m_userInputManager.GetMouse(), controlledGWO, (float)GWOSpeedMultByFrametime, m_camera, m_fileIO, m_MainGWOContainer);
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
	if (m_drawHitboxMode)
	{
		for (auto & gwo : m_MainGWOContainer)
		{
			m_camera.DrawHitbox(*gwo);
		}
	}
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