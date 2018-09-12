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

class FileOutput;

class Game
{
public:
	Game( Camera & camera, UserInputManager & UIM );

	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;

	void Go();

private:

	void BeginFrame();
	void UpdateInput();
	void UpdateController();
	void UpdateModel();
	void UpdateOutput();

	// INPUT
	FileOutput m_fileOutput;

	// CONTROLLER
	UserInputManager & m_userInputManager;

	// MODEL
	std::vector<std::unique_ptr<GWO>> m_mainGWOContainer; //move camera into this???
	CreatureCreator m_creatureCreator;

	// OUTPUT
	Camera & m_camera;

	//MISC
	Clock m_clock;
	bool m_drawHitboxMode = true;



	


};