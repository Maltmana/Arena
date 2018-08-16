#include "Camera.h"
#include "GWO.h"
#include "GameMath.h"

Camera::Camera(Graphics & graphics)
	:
	m_graphics{ graphics }
{
}
// all connections between game and graphics go through camera object. Begins with making drawable out of GWO and applying entities position and scale onto its drawable
void Camera::DrawHitbox(GWO const & gWO) const
{

	// TODO : seperate this three steps into seperate functions
	// apply GWObjects scale and world position
	Drawable drawable(gWO.m_logicComponent->getHitbox(), gWO.m_graphicsComponent->GetHitboxColor());
	drawable.Scale(gWO.m_scale);
	drawable.Translate(gWO.m_position);

	// apply Cameras position and scale
	drawable.Translate(-m_position);
	drawable.Scale(m_scale);

	// apply GameWorld Coordinates to be Window Coordinates to prepare for the put pixel calls in render
	drawable.SetTranslate(GameMath::GameWorldCoordinatesToWindowCoordinates(drawable.GetTranslateCopy(), m_graphics)); // this needs to be a SetTranslate because we are multiplying the translate not just adding
	
	// put pixel calls on the closed polyline
	drawable.Render(m_graphics);
}

void Camera::BeginFrame()
{
	m_graphics.BeginFrame();
}

void Camera::EndFrame()
{
	m_graphics.EndFrame();
}
