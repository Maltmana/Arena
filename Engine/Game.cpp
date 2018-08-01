/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"
Game::Game(Camera & camera, UserInputManager & userInputManager)
	:
	c{ humanModel, "human", 50, 10.f, Vec2{ 0.f,0.f }, Colors::Red},
	o{ ogreModel, "ogre", 100, 20.f, Vec2{ 100.f,0.f }, Colors::Blue },
	s{ serpentModel, "serpent", 30, 40.f, Vec2{ -100.f,0.f }, Colors::Green },
	ss{ serpentModel, "serpent", 30, 40.f, Vec2{ -200.f,0.f }, Colors::Green },
	m_camera{ camera },
	m_userInputManager{userInputManager}
	

{

	creatureManager.AddCreature(c);
	creatureManager.AddCreature(o);
	creatureManager.AddCreature(s);

}

void Game::Go()
{
	m_camera.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	m_camera.EndFrame();
}

void Game::UpdateModel()
{
	m_userInputManager.HandleInput();

	double frameTime = m_frameClock.GetCounterS();
	m_frameClock.StartCounter();

	/*
	float speed = 100.f*frameTime; // pixels per second

		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			if (m_followC)
			{
				creatureManager.creatures.back().SetPos(creatureManager.creatures.back().GetPos() - Vec2{speed, 0.f});
			}
			else
			{
				m_camera.MoveBy({ speed,0.f });
			}

		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			if (m_followC)
			{
				creatureManager.creatures.back().SetPos(creatureManager.creatures.back().GetPos() - Vec2{ -speed, 0.f });
			}
			else
			{
				m_camera.MoveBy({ -speed,0.f });
			}
		}
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			if (m_followC)
			{
				creatureManager.creatures.back().SetPos(creatureManager.creatures.back().GetPos() - Vec2{ 0.f, speed});
			}
			else
			{
				m_camera.MoveBy({ 0.f,speed });
			}
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			if (m_followC)
			{
				creatureManager.creatures.back().SetPos(creatureManager.creatures.back().GetPos() - Vec2{ 0.f,-speed });
			}
			else
			{
				m_camera.MoveBy({ 0.f,-speed });
			}
		}

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
	for (auto & c : creatureManager.creatures)
	{
		c.Update(m_camera);
	}

	ss.Update(m_camera);

	//const std::vector<Vec2> GUIrect = { {-200, -200}, { 0,0 } };
	//Entity GUI(GUIrect, camera.GetPos(), Colors::Magenta);

	//GUI.Update(camera);
}
