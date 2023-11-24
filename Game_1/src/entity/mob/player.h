#pragma once

#include "human.h"
#include "../../graphics/window.h"

namespace entity {

	class Player : public Human {
	private:
		graphics::Window* m_Window;
		float speed = 20.0f;
		float sens = 10.0f;
	public:
		Player(graphics::Mesh* mesh, graphics::Renderable* renderable, glm::vec3 position, graphics::Window* window);
		void update(float dt);
		void move(glm::vec3 pa);
	};

}