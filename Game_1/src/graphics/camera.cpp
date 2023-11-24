#include "camera.h"

namespace graphics {

	Camera::Camera(Shader* shader)
		: m_Shader(shader)
	{
		m_Position = glm::vec3(0.0f);
		m_Rotation = glm::vec3(0.0f);
	}

	Camera::Camera(glm::vec3 position, glm::vec3 rotation, Shader* shader)
		: m_Position(position), m_Rotation(rotation), m_Shader(shader)
	{
	}

	void Camera::init()
	{
		// m_Projection = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
		m_Projection = glm::perspective(70.0f, 16.0f / 9.0f, 0.01f, 5000.0f);
		m_Shader->setUniformMat4("pr_matrix", m_Projection);
	}

	void Camera::update(float dt)
	{
		glm::mat4 view_matrix = glm::rotate(glm::mat4(1.0f), to_radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		view_matrix *= glm::rotate(glm::mat4(1.0f), to_radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		view_matrix *= glm::translate(glm::mat4(1.0f), m_Position);
		m_Shader->setUniformMat4("vw_matrix", view_matrix);
	}

	void Camera::setPosition(const glm::vec3& position)
	{
		m_Position = position;
	}

	void Camera::setRotation(const glm::vec3& rotation)
	{
		m_Rotation = rotation;
	}

}