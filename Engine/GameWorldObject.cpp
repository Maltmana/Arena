#include "GameWorldObject.h"
#include "Drawable.h"

// Automatically initializes component unique_ptrs to null


GameWorldObject::GameWorldObject()
{
}

GameWorldObject::GameWorldObject(std::unique_ptr<GraphicsComponent> graphicsComponent, std::unique_ptr<InputComponent> inputComponent, std::unique_ptr<LogicComponent> logicComponent )
	:
	m_graphicsComponent( std::move(graphicsComponent) ),
	m_inputComponent( std::move(inputComponent) ),
	m_logicComponent( std::move(logicComponent) )
{
}

void GameWorldObject::GraphicsUpdate(Camera const & camera) const
{
	//m_graphicsComponent->Update(*this, camera); // TODO : remove raw pointer.
}


