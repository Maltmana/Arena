#pragma once
#include "pch.h"

/* hitbox for now */
class LogicComponent
{
public:
	LogicComponent(std::vector<Vec2> hitbox, std::string typeOf)
		:
		m_hitbox{ hitbox },
		m_typeOf{ typeOf }
	{
	
	}
	const std::vector<Vec2> & getHitbox() const { return m_hitbox; };

	std::string m_typeOf;

private:
	std::vector<Vec2> m_hitbox;
};