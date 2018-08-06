#include "GraphicsComponent.h"
#include "Camera.h"
#include "GO.h"

void GraphicsComponent::Update(GO & gO, Camera & camera)
{
	DrawHitbox(gO, camera);
}

void GraphicsComponent::DrawHitbox(GO & gO, Camera & camera) const
{
	camera.DrawHitbox(gO);
}
