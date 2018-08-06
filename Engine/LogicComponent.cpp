#include "LogicComponent.h"

LogicComponent::LogicComponent(std::vector<Vec2> hitbox, std::string typeName)
	:
	m_hitbox{ hitbox },
	m_typeName{ typeName }
{}
