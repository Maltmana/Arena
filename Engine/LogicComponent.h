#pragma once
#include "pch.h"

/* hitbox for now */
class LogicComponent
{
public:
	LogicComponent(std::vector<Vec2> hitbox, std::string typeName);

	std::vector<Vec2> getHitbox() const { return m_hitbox; };
	std::string getTypeName() const { return m_typeName; };

private:
	std::string m_typeName;
	std::vector<Vec2> m_hitbox;
};