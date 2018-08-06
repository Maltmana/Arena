#pragma once

#include "pch.h"
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "LogicComponent.h"

class Drawable;

class GO 
{

public:		

	// Initializes unique_ptr components to null
	GO();

	// Calls std::move on each parameter
	GO(std::unique_ptr<GraphicsComponent> graphicsComponent,
		std::unique_ptr<InputComponent> inputComponent,
		std::unique_ptr<LogicComponent> logicComponent);

	// Calls update on the graphics component
	void GraphicsUpdate(Camera const & camera) const;

	// TODO : Set these into the graphics component? or a different level of inheritance?
	 std::vector<Vec2> GetHitbox() const { return m_logicComponent->getHitbox(); };
	 Color GetColor() const { return m_graphicsComponent->GetColor(); };

	 Vec2 m_position = { 0,0 };
	 float m_scale = 1.0f; // scale is for camera which is also a GO

private:

	std::unique_ptr<GraphicsComponent> m_graphicsComponent;
	std::unique_ptr<LogicComponent> m_logicComponent;
	std::unique_ptr<InputComponent> m_inputComponent;




};