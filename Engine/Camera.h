#pragma once
#include "Vec2.h"

#include "CoordinateTransformer.h"

#include "Graphics.h"

class Entity;

class Camera
{
public:

	Camera(Graphics & graphics);

	void MoveBy(const Vec2 & offset);
	void MoveTo(const Vec2 & pos);
	/*Takes Entities vertices model, applies transform based on entities position and then sends it down rendering pipeline*/
	void DrawHitbox(Entity & entity) const;

	Vec2 GetPos() const { return m_pos; };
	float GetScale() const { return m_scale; };
	void SetScale(float scale) { m_scale = scale; };

	void BeginFrame();
	void EndFrame();



private:
	static int numberOfCameras;
	Vec2 m_pos = { 0.f,0.f };
	CoordinateTransformer m_ct;
	float m_scale = 1.f;

	Graphics & m_graphics;

};

//int Camera::numberOfCameras = 0;