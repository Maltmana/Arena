#pragma once
#include "Vec2.h"
#include <assert.h>

#include "GraphicsComponent.h"
#include "LogicComponent.h"
#include "InputComponent.h"


class Drawable;

class GameWorldObject 
{
public:

	Vec2 m_position;
	Vec2 m_velocity;
	float m_scale;

	GameWorldObject(Vec2 position = { 0,0 }, Vec2 velocity = { 0,0 }, GraphicsComponent * graphicsComponent = nullptr, LogicComponent * logicComponent = nullptr, InputComponent * inputComponent = nullptr);

	//const Vec2 & GetPos() const { return m_position; };
	//const float GetScale() const { return m_scale; };
	//void SetPos(const Vec2& position) { m_position = position; };
	//void SetScale(const float scale) { m_scale = scale; };

	// TODO : Set these into the graphics component? or a different level of inheritance?
	const std::vector<Vec2> & GetHitbox() const { return m_logicComponent->getHitbox(); };
	const Color & GetColor() const { return m_graphicsComponent->GetColor(); };

	void MoveBy(const Vec2 offset);

	void Update(Camera & camera); // TODO : put in cpp


private:
	GraphicsComponent * m_graphicsComponent;
	LogicComponent * m_logicComponent;
	InputComponent * m_inputComponent;



};



//	// TODO : Set these into the graphics component? or a different level of inheritance?
//	const std::vector<Vec2> & GetHitbox() const { return m_hitbox; };
//	const Color & GetColor() const { return m_graphicsComponent.GetColor(); };

