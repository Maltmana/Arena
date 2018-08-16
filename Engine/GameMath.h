#pragma once
#include "pch.h"
#include "Drawable.h"
#include "GWO.h"

static class GameMath
{
public:
	// Copies position. Inverts Y axis for windows. Centers pos 0, 0 to be at center of camera when it is at pos 0, 0. Returns copy.
	static Vec2 GameWorldCoordinatesToWindowCoordinates(Vec2 pos, Graphics const & graphics)
	{
		pos.y *= -1;
		pos += { float(graphics.ScreenWidth / 2), float(graphics.ScreenHeight / 2) };
		return pos; // assert that a pos of pos of 0,0 results in a window coord of 
	}

	static Vec2 WindowCoordinatesToGameWorldCoordinates(Vec2 pos, Camera const & camera)
	{

		pos -= { float(camera.GetScreenWidth() / 2), float(camera.GetScreenHeight()/ 2) };
		pos.y *= -1;
		pos += camera.m_position;

		return pos;
	}
};