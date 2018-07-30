#pragma once
#include "Vec2.h"
#include <vector>
#include <assert.h>
#include "Colors.h"
#include "GraphicsComponent.h"

class Drawable;

class Entity
{
public:
	Entity(const std::vector<Vec2> & hitbox, const Vec2 & pos = { 0.f, 0.f }, Color c = Colors::Green);

	void Update(Camera & camera) // TODO : put in cpp
	{
		m_graphicsComponent.Update(*this, camera ); // TODO : remove raw pointer.
	}

	const Vec2 & GetPos() const { return m_pos; };
	void SetPos(const Vec2& pos) { m_pos = pos; };
	const float GetScale() const { return m_graphicsComponent.GetScale(); };
	void SetScale(const float scale) { m_graphicsComponent.SetScale(scale); };
	const std::vector<Vec2> & GetHitbox() const { return m_hitbox; };
	const Color & GetColor() const { return m_graphicsComponent.GetColor(); };


private:
	GraphicsComponent m_graphicsComponent;
	std::vector<Vec2> m_hitbox;
	Vec2 m_pos;

};
