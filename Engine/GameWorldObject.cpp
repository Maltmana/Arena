#include "GO.h"
#include "Drawable.h"

// Automatically initializes component unique_ptrs to null


GO::GO()
{
}

GO::GO(std::unique_ptr<GraphicsComponent> graphicsComponent, std::unique_ptr<InputComponent> inputComponent, std::unique_ptr<LogicComponent> logicComponent )
	:
	m_graphicsComponent( std::move(graphicsComponent) ),
	m_inputComponent( std::move(inputComponent) ),
	m_logicComponent( std::move(logicComponent) )
{
}

void GO::GraphicsUpdate(Camera const & camera) const
{
	//m_graphicsComponent->Update(*this, camera); // TODO : remove raw pointer.
}


