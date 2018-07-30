#include "Entity.h"
#include "Drawable.h"


Entity::Entity(const std::vector<Vec2>& hitbox, const Vec2 & pos, Color c)
	:
	m_hitbox{std::move(hitbox)},
	m_pos{pos},
	m_graphicsComponent{c}
{
}
