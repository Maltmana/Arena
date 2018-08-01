#include "GameWorldObject.h"
#include "Drawable.h"


GameWorldObject::GameWorldObject(Vec2 position, Vec2 velocity, GraphicsComponent * graphicsComponent, LogicComponent * logicComponent, InputComponent * inputComponent)
	:
	m_position{ position },
	m_velocity{velocity},
	m_graphicsComponent{ graphicsComponent },
	m_logicComponent{ logicComponent },
	m_inputComponent{inputComponent}
{
}

void GameWorldObject::Update(Camera & camera)
{
	m_graphicsComponent->Update(*this, camera); // TODO : remove raw pointer.
}

void GameWorldObject::MoveBy(const Vec2 offset)
{
	{
		m_position += offset;
	}
}


