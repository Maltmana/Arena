#include "Drawable.h"

Drawable::Drawable(std::vector<Vec2> model, Color c)
	:
	m_model{ model },
	m_c{ c }
{}

void Drawable::Translate(const Vec2 & translation)
{
	m_translation += translation;
}

void Drawable::Scale(float scale)
{
	m_scaleX *= scale;
	m_scaleY *= scale;
	m_translation *= scale;
}

void Drawable::ScaleIndependent(float scaleX, float scaleY)

{
	m_scaleX *= scaleX;
	m_scaleY *= scaleY;
}

void Drawable::Render(Graphics & gfx)
{
	for (auto & v : m_model)
	{
		v.x *= m_scaleX;
		v.y *= m_scaleY;
		v += m_translation;
	}
	gfx.DrawClosedPolyline(m_model, m_c);
}