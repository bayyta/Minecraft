#include "player.h"

namespace entity {

	Player::Player(graphics::Mesh* mesh, graphics::Renderable* renderable, glm::vec3 position, graphics::Window* window)
		: Human(mesh, renderable, position), m_Window(window)
	{
		m_Window->hideMouse();
	}

	void Player::update(float dt)
	{
		if (m_Window->keyPressed(GLFW_KEY_W))
		{
			move(glm::vec3(-sin(to_radians(m_Rotation.y)) * dt, 0, cos(to_radians(m_Rotation.y)) * dt) * speed);
		}
		if (m_Window->keyPressed(GLFW_KEY_D))
		{
			move(glm::vec3(-sin(to_radians(m_Rotation.y + 90.0f)) * dt, 0, cos(to_radians(m_Rotation.y + 90.0f)) * dt) * speed);
		}
		if (m_Window->keyPressed(GLFW_KEY_S))
		{
			move(glm::vec3(sin(to_radians(m_Rotation.y)) * dt, 0, -cos(to_radians(m_Rotation.y)) * dt) * speed);
		}
		if (m_Window->keyPressed(GLFW_KEY_A))
		{
			move(glm::vec3(-sin(to_radians(m_Rotation.y - 90.0f)) * dt, 0, cos(to_radians(m_Rotation.y - 90.0f)) * dt) * speed);
		}
		if (m_Window->keyPressed(GLFW_KEY_SPACE))
			move(glm::vec3(0, -speed * dt, 0));
		if (m_Window->keyPressed(GLFW_KEY_LEFT_SHIFT))
			move(glm::vec3(0, speed * dt, 0));

		if (!m_Window->isMouseCentered())
		{
			double mx, my;
			m_Window->getMousePosition(mx, my);
			m_Rotation.y += sens * dt * (mx - m_Window->getWidth() / 2);
			m_Rotation.x += sens * dt * (my - m_Window->getHeight() / 2);
			m_Window->centerMousePosition();
		}
	}

	void Player::move(glm::vec3 pa)
	{
		m_Position += pa;
	}

}