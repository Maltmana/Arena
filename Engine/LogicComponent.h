#pragma once
#include <vector>

class LogicComponent
{
public:
	LogicComponent(std::vector<Vec2> & hitbox)
		:
		m_hitbox{ hitbox }
	{
	
	}
	const std::vector<Vec2> & getHitbox() const { return m_hitbox; };
private:
	std::vector<Vec2> m_hitbox;
};