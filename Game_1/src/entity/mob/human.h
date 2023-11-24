#pragma once

#include "mob.h"

namespace entity {

	class Human : public Mob {
	public:
		Human(graphics::Mesh* mesh, graphics::Renderable* renderable, glm::vec3 position);
		void update(float dt);
	};

}