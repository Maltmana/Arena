#include "Camera.h"
#include "CoordinateTransformer.h"
#include "Entity.h"

Camera::Camera(CoordinateTransformer & ct)
	:
	m_ct{ ct }
{}

void Camera::MoveBy(const Vec2 & offset)
{
	m_pos += offset;
}

void Camera::MoveTo(const Vec2 & pos)
{
	m_pos = pos;
}

void Camera::DrawHitbox(Entity & entity) const
{
	// all connections between game and graphics go through camera object. Begins with making drawable out of entity and applying entities position and scale onto its drawable.
	Drawable drawable(entity.GetHitbox(), entity.GetColor());
	drawable.Scale(entity.GetScale());
	drawable.Translate(entity.GetPos());

	drawable.Translate(-m_pos);
	drawable.Scale(m_scale);
	m_ct.Draw(drawable);
}