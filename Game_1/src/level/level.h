#pragma once

#include <cmath>
#include "generation/perlinNoise.h"
#include "../graphics/window.h"
#include "../graphics/layers/layer3d.h"
#include "../graphics/layers/batch3d.h"
#include "../graphics/renderables/block.h"
#include "../graphics/renderers/batchrenderer3d.h"
#include "../entity/mob/player.h"
#include "../graphics/camera.h"

namespace level {

	class Level {
	private:
		graphics::Window* m_Window;
		graphics::Texture *grass, *dirt, *stone;
		graphics::Shader* shader;
		graphics::Batch3D* batch3d;
		entity::Player* m_Player;
		graphics::Camera* m_Camera;
	public:
		Level(graphics::Window* window);
		~Level();
		void update(float dt);
		void render();
	private:
		void init();
		void generateLevel();
	};

}