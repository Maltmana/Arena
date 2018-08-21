#include "GWO.h"
#include "Drawable.h"


GWO::GWO(std::string gwoTitle)
	:
	m_gwoTitle{ gwoTitle }
{
}

GWO::GWO(std::string gwoTitle, std::unique_ptr<GraphicsComponent> graphicsComponent, std::unique_ptr<InputComponent> inputComponent, std::unique_ptr<LogicComponent> logicComponent)
	:
	m_gwoTitle{ gwoTitle },
	m_graphicsComponent( std::move(graphicsComponent) ),
	m_inputComponent( std::move(inputComponent) ),
	m_logicComponent( std::move(logicComponent) )

{
}

void GWO::GraphicsUpdate(Camera const & camera) const
{
}


