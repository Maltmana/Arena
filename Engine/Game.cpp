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
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ct(gfx),
	cam(ct),
	c{ humanModel, "human", 50, 10.f, Vec2{ 0.f,0.f }, Colors::Red},
	o{ ogreModel, "ogre", 100, 20.f, Vec2{ 100.f,0.f }, Colors::Blue },
	s{ serpentModel, "serpent", 30, 40.f, Vec2{ -100.f,0.f }, Colors::Green },
	ss{ serpentModel, "serpent", 30, 40.f, Vec2{ -200.f,0.f }, Colors::Green }

{

	//entities.emplace_back(Star::Make(100.f, 50.f), Vec2{ -300.f,0.f });
	creatureManager.AddCreature(c);
	creatureManager.AddCreature(o);
	creatureManager.AddCreature(s);



}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	double frameTime = m_frameClock.GetCounterS();
	m_frameClock.StartCounter();

	// TODO : speed in pixels per second
	float speed = 100.f*frameTime;

		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			if (m_followC)
			{
				creatureManager.creatures.back().SetPos(creatureManager.creatures.back().GetPos() - Vec2{speed, 0.f});
			}
			else
			{
				cam.MoveBy({ speed,0.f });
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
				cam.MoveBy({ -speed,0.f });
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
				cam.MoveBy({ 0.f,speed });
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
				cam.MoveBy({ 0.f,-speed });
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
			cam.MoveTo(creatureManager.creatures.back().GetPos());
		}


		while (!wnd.mouse.IsEmpty())
		{
			const auto mr = wnd.mouse.Read();
			if (mr.GetType() == Mouse::Event::Type::WheelUp)
			{
				cam.SetScale(cam.GetScale() * 1.05f);
			}
			if (mr.GetType() == Mouse::Event::Type::WheelDown)
			{
				cam.SetScale(cam.GetScale() * 0.95f);
			}
		}

		if (wnd.kbd.KeyIsPressed(VK_CONTROL))
		{
			creatureManager.CreateCreature("human", cam.GetPos());
		}

}
	
void Game::ComposeFrame()
{
	for (auto & c : creatureManager.creatures)
	{
		c.Update(cam);
	}

	ss.Update(cam);

}
