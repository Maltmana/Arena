#pragma once
#include "Vec2.h"

#include "CoordinateTransformer.h"

#include "Graphics.h"

#include "GameWorldObject.h"

class Camera : public GameWorldObject // TODO : elegantly prevent multiple Cameras from existing.
{
public:

	Camera() = delete;
	Camera(Graphics & graphics);
	Camera(const Camera & camera)
		:
		m_ct{camera.m_ct},
		m_graphics{camera.m_graphics}
	{
		numberOfCameras++;
		assert(numberOfCameras < 2);
	}
	Camera& operator=(Camera camera)
	{
		numberOfCameras++;
		assert(numberOfCameras < 2);
	}


	/*Takes Entities vertices model, applies transform based on entities position and then sends it down rendering pipeline*/
	void DrawHitbox(GameWorldObject & gameWorldObject) const;

	void BeginFrame();
	void EndFrame();



private:
	static int numberOfCameras;

	CoordinateTransformer m_ct;
	Graphics & m_graphics;

};

