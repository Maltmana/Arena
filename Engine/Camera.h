#pragma once
#include "Vec2.h"

#include "Graphics.h"

#include "GWO.h"

class Camera : public GWO // TODO : elegantly prevent multiple Cameras from existing.
{
public:

	Camera() = delete;
	Camera(Graphics & graphics);
	Camera(const Camera & camera) // TODO : put this in cpp
		:
		GWO(),
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
	void DrawHitbox(GWO const & GWO) const;

	void BeginFrame();
	void EndFrame();

	int GetScreenWidth() const { return m_graphics.ScreenWidth; };
	int GetScreenHeight() const { return m_graphics.ScreenHeight; };




private:
	static int numberOfCameras;

	Graphics & m_graphics;

};

