#pragma once
#include "Colors.h"


class GameWorldObject;
class Camera;

/*Sole interactor with camera class which is the sole interactor with gfx via the rendering pipeline. Sends data to be processed by Camera.*/
class GraphicsComponent
{
public:
	GraphicsComponent( const Color & color)
		:
		m_color{color}
	{}

	void Update(GameWorldObject & gameWorldObject, Camera & camera);

	void DrawHitbox(GameWorldObject & gameWorldObject, Camera & camera) const;

	const float GetScale() const { return m_scale; };
	void SetScale(const float scale) { m_scale = scale; };
	const Color & GetColor() const { return m_color; };

	Color m_color;
	float m_scale = 1.f;
};