#include "GraphicsComponent.h"
#include "Camera.h"
#include "GameWorldObject.h"

void GraphicsComponent::Update(GameWorldObject & gameWorldObject, Camera & camera)
{
	DrawHitbox(gameWorldObject, camera);
}

void GraphicsComponent::DrawHitbox(GameWorldObject & gameWorldObject, Camera & camera) const
{
	camera.DrawHitbox(gameWorldObject);
}
