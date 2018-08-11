/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Mouse.h																				  *
 *	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
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
#include <queue>
#include "Vec2.h"

class Mouse
{
	friend class MainWindow;
public:
	class Event
	{
	public:
		enum class Type
		{
			LPress,
			LRelease,
			RPress,
			RRelease,
			WheelUp,
			WheelDown,
			Move,
			Invalid
		};
	private:
		Type type;
		bool leftIsPressed;
		bool rightIsPressed;
		bool leftIsReleased;
		bool rightIsReleased;
		int x;
		int y;
	public:
		Event()
			:
			type( Type::Invalid ),
			leftIsPressed( false ),
			rightIsPressed( false ),
			leftIsReleased(false),
			rightIsReleased(false),
			x( 0 ),
			y( 0 )
		{}
		Event( Type type,const Mouse& parent )
			:
			type( type ),
			leftIsPressed( parent.leftIsPressed ),
			rightIsPressed( parent.rightIsPressed ),
			leftIsReleased(parent.leftIsReleased),
			rightIsReleased(parent.rightIsReleased),
			x( parent.x ),
			y( parent.y )
		{}
		bool IsValid() const
		{
			return type != Type::Invalid;
		}
		Type GetType() const
		{
			return type;
		}
		Vei2 GetPos() const
		{
			return{ x,y };
		}
		int GetPosX() const
		{
			return x;
		}
		int GetPosY() const
		{
			return y;
		}
		bool LeftIsPressed() const
		{
			return leftIsPressed;
		}
		bool RightIsPressed() const
		{
			return rightIsPressed;
		}
		bool LeftIsReleased() const
		{
			return leftIsReleased;
		}

		bool RightIsReleased() const
		{
			return rightIsReleased;
		}
	};
public:
	Mouse() = default;
	Mouse( const Mouse& ) = delete;
	Mouse& operator=( const Mouse& ) = delete;
	Vei2 GetPos() const;
	int GetPosX() const;
	int GetPosY() const;
	bool LeftIsPressed() const;
	bool RightIsPressed() const;

	// TODO : implement
	bool RightIsClickedOnce();
	// modifies member bool leftIsReleased to false, otherwise it spams event after 1 release
	bool LeftIsReleased();
	// modifies member bool rightIsReleased to false, otherwise it spams event after 1 release
	bool RightIsReleased();
	bool IsInWindow() const;
	// reads front of event buffer. pops off one.
	Mouse::Event Read();
	bool IsEmpty() const
	{
		return buffer.empty();
	}
	void Flush();
private:
	void OnMouseMove( int x,int y );
	void OnMouseLeave();
	void OnMouseEnter();
	void OnLeftPressed( int x,int y );
	void OnRightPressed( int x,int y );
	// causes release of leftIsPressed by switching member bool leftIsPressed to false
	void OnLeftReleased(int x, int y);
	// causes release of rightIsPressed by switching member bool rightIsPressed to false
	void OnRightReleased( int x,int y );
	void OnWheelUp( int x,int y );
	void OnWheelDown( int x,int y );
	void TrimBuffer();
private:
	static constexpr unsigned int bufferSize = 4u;
	int x;
	int y;
	bool leftIsPressed = false;
	bool rightIsPressed = false;
	bool leftIsReleased = false;
	bool rightIsReleased = false;
	bool rightWasPressedLastTick = false;
	bool isInWindow = false;
	std::queue<Event> buffer;
};