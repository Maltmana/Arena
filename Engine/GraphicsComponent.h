#pragma once
#include "Colors.h"


class GO;
class Camera;

/*Sole interactor with camera class which is the sole interactor with gfx via the rendering pipeline. Sends data to be processed by Camera. color only for now */
class GraphicsComponent
{
public:
	GraphicsComponent()
	{}

	GraphicsComponent( const Color color)
		:
		m_color{color}
	{}

	void Update(GO & gO, Camera & camera);

	void DrawHitbox(GO & gO, Camera & camera) const;

	const Color GetColor() const { return m_color; };

	Color m_color;
};