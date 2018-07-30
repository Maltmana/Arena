#include "GraphicsComponent.h"
#include "Camera.h"
#include "Entity.h"

void GraphicsComponent::Update(Entity & entity, Camera & camera)
{
	DrawHitbox(entity, camera);
}

void GraphicsComponent::DrawHitbox(Entity & entity, Camera & camera) const
{
	camera.DrawHitbox(entity);
}
