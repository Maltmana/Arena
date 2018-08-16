#pragma once

#include "pch.h"
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "LogicComponent.h"

class Drawable;

class GWO 
{

public:		

	// Initializes unique_ptr components to null
	GWO();

	// Calls std::move on each parameter
	GWO(std::unique_ptr<GraphicsComponent> graphicsComponent,
		std::unique_ptr<InputComponent> inputComponent,
		std::unique_ptr<LogicComponent> logicComponent);

	// UNIMPLEMENTED Calls update on the graphics component
	void GraphicsUpdate(Camera const & camera) const;

	 Vec2 m_position = { 0,0 };
	 float m_scale = 1.0f; // scale is for camera which is also a GWO

	std::unique_ptr<GraphicsComponent> m_graphicsComponent;
	std::unique_ptr<LogicComponent> m_logicComponent;
	std::unique_ptr<InputComponent> m_inputComponent;




};