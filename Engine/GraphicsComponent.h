#pragma once
#include "Colors.h"

class GO;
class Camera;

/*Sole interactor with camera class which is the sole interactor with gfx via the rendering pipeline. Sends data to be processed by Camera. color only for now */
class GraphicsComponent
{

public:

	GraphicsComponent();
	// Sets color of hitbox
	GraphicsComponent(Color const hitboxColor);

	Color GetHitboxColor() const { return m_hitboxColor; };
	void SetHitboxColor(Color const hitboxColor) { m_hitboxColor = hitboxColor; };

private:

	Color m_hitboxColor;

};