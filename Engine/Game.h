/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once


#include "Star.h"
#include "GWO.h"
#include "Creature.h"
#include "Camera.h"
#include "Rect.h"
#include "Clock.h"
#include "UserInputManager.h"
#include "CreatureCreator.h"

class FileIO;

class Game
{
public:
	Game( Camera & camera, UserInputManager & UIM );

	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;

	void Go();

private:
	void ComposeFrame();
	void UpdateModel();

	// SUPER COMPONENTS
	Camera & m_camera;
	UserInputManager & m_userInputManager;
	FileIO m_fileIO;

	Clock m_clock;

	//Game World Stuff

	std::vector<std::unique_ptr<GWO>> m_MainGWOContainer;

	// GWO Creators
	CreatureCreator m_creatureCreator;


	// TO BE ORGANIZED BETTER AND MORE MODULARLY

	bool m_drawHitboxMode = true;

public:
	static bool m_SaveGameFlag;

	


};