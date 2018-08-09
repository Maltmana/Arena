#pragma once
#include "Vec2.h"
#include <vector>
#include "Colors.h"
#include "Graphics.h"
class Drawable
{
public:
	Drawable(std::vector<Vec2> model, Color c);

	void Translate(const Vec2& translation);

	void Scale(float scale);

	void ScaleIndependent(float scaleX, float scaleY);

	void ConvertTranslationFromWindowsYCoordToCartesianYCoord();

	void Render(Graphics & gfx);

private:
	Color m_c;
	std::vector<Vec2> m_model;
	float m_scaleX = 1.f;
	float m_scaleY = 1.f;
	Vec2 m_translation = { 0.f, 0.f };
};