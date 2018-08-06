#include "Camera.h"
#include "CoordinateTransformer.h"
#include "GameWorldObject.h"

Camera::Camera(Graphics & graphics)
	:
	m_graphics{ graphics },
	m_ct{graphics}
{
}
// all connections between game and graphics go through camera object. Begins with making drawable out of gameWorldObject and applying entities position and scale onto its drawable.
void Camera::DrawHitbox(GameWorldObject & gameWorldObject) const
{
	
	Drawable drawable(gameWorldObject.GetHitbox(), gameWorldObject.GetColor());
	drawable.Scale(gameWorldObject.m_scale);
	drawable.Translate(gameWorldObject.m_position);

	drawable.Translate(-m_position);
	drawable.Scale(m_scale);
	m_ct.Draw(drawable);
}

void Camera::BeginFrame()
{
	m_graphics.BeginFrame();
}

void Camera::EndFrame()
{
	m_graphics.EndFrame();
}
