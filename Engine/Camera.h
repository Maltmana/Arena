#pragma once
#include "Vec2.h"

#include "CoordinateTransformer.h"

#include "Graphics.h"

#include "GameWorldObject.h"

class Camera : public GameWorldObject
{
public:

	Camera(Graphics & graphics);

	/*Takes Entities vertices model, applies transform based on entities position and then sends it down rendering pipeline*/
	void DrawHitbox(GameWorldObject & gameWorldObject) const;

	void BeginFrame();
	void EndFrame();



private:
	static int numberOfCameras;
	Vec2 m_pos = { 0.f,0.f };
	float m_scale = 1.f;

	CoordinateTransformer m_ct;
	Graphics & m_graphics;

};

