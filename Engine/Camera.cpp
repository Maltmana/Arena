#include "Camera.h"
#include "CoordinateTransformer.h"
#include "GO.h"

Camera::Camera(Graphics & graphics)
	:
	m_graphics{ graphics },
	m_ct{graphics}
{
}
// all connections between game and graphics go through camera object. Begins with making drawable out of GO and applying entities position and scale onto its drawable.
void Camera::DrawHitbox(GO & gO) const
{
	Drawable drawable(gO.m_logicComponent->getHitbox(), gO.m_graphicsComponent->GetHitboxColor());
	drawable.Scale(gO.m_scale);
	drawable.Translate(gO.m_position);

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
