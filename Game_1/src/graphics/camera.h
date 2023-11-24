#pragma once

#include <glm/glm.hpp>
#include "shader.h"

namespace graphics {

	class Camera {
	private:
		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		glm::mat4 m_Projection;
		Shader* m_Shader;
	public:
		Camera(Shader* shader);
		Camera(glm::vec3 position, glm::vec3 rotation, Shader* shader);
		void init();
		void update(float dt);
		void setPosition(const glm::vec3& position);
		void setRotation(const glm::vec3& rotation);
		inline const glm::vec3& const getPosition() { return m_Position; }
		inline const glm::vec3& const getRotation() { return m_Rotation; }
	};

}