#pragma once

#include <glm/glm.hpp>
#include "../../graphics/renderables/mesh.h"
#include "../../graphics/renderables/renderable.h"

namespace entity {

	class Mob {
	protected:
		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		graphics::Mesh* m_Mesh;
		graphics::Renderable* m_Renderable;
	public:
		virtual ~Mob() { }
		virtual void update(float dt) = 0;
		inline const graphics::Mesh* const getMesh() { return m_Mesh; }
		inline const graphics::Renderable* const getRenderable() { return m_Renderable; }
		inline const glm::vec3& const getPosition() { return m_Position; }
		inline const glm::vec3& const getRotation() { return m_Rotation; }
	};

}