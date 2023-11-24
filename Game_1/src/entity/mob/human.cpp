#include "human.h"

namespace entity {

	Human::Human(graphics::Mesh* mesh, graphics::Renderable* renderable, glm::vec3 position)
	{
		m_Mesh = mesh;
		m_Renderable = renderable;
		m_Position = position;
		m_Rotation = glm::vec3();
	}

	void Human::update(float dt)
	{
	}

}