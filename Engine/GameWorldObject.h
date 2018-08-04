#pragma once

#include "pch.h"
#include "GraphicsComponent.h"
#include "LogicComponent.h"
#include "InputComponent.h"




class Drawable;

class GameWorldObject 
{
public:

	Vec2 m_position = { 0,0 };
	Vec2 m_velocity = { 0,0 };
	float m_scale = 1.0f;
		
	GameWorldObject() {};
	GameWorldObject(std::unique_ptr<GraphicsComponent> graphicsComponent, std::unique_ptr<InputComponent> inputComponent, std::unique_ptr<LogicComponent> logicComponent);

	//const Vec2 & GetPos() const { return m_position; };
	//const float GetScale() const { return m_scale; };
	//void SetPos(const Vec2& position) { m_position = position; };
	//void SetScale(const float scale) { m_scale = scale; };

	// TODO : Set these into the graphics component? or a different level of inheritance?
	const std::vector<Vec2> & GetHitbox() const { return m_logicComponent->getHitbox(); };
	const Color & GetColor() const { return m_graphicsComponent->GetColor(); };

	void MoveBy(const Vec2 offset);

	void Update(Camera & camera); // TODO : put in cpp


	// these auto initialize to null
	std::unique_ptr<GraphicsComponent> m_graphicsComponent;
	std::unique_ptr<LogicComponent> m_logicComponent;
	std::unique_ptr<InputComponent> m_inputComponent;



};



//	// TODO : Set these into the graphics component? or a different level of inheritance?
//	const std::vector<Vec2> & GetHitbox() const { return m_hitbox; };
//	const Color & GetColor() const { return m_graphicsComponent.GetColor(); };

