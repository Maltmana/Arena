#include "Camera.h"
#include "CoordinateTransformer.h"
#include "GWO.h"

Camera::Camera(Graphics & graphics)
	:
	m_graphics{ graphics },
	m_ct{graphics}
{
}
// all connections between game and graphics go through camera object. Begins with making drawable out of GWO and applying entities position and scale onto its drawable.
void Camera::DrawHitbox(GWO const & gWO) const
{
	Drawable drawable(gWO.m_logicComponent->getHitbox(), gWO.m_graphicsComponent->GetHitboxColor());
	drawable.Scale(gWO.m_scale);
	drawable.Translate(gWO.m_position);

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
