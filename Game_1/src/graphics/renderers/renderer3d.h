#pragma once

#include <deque>

#include "renderer.h"
#include "../renderables/renderable.h"
#include "../renderables/mesh.h"

namespace graphics {

	class Renderer3D : public Renderer
	{
	private:
		std::deque<const Mesh*> m_Meshes;
		std::deque<const Renderable*> m_Renderables;
	public:
		void submit(const Mesh* mesh, const Renderable* renderable);
		void flush() override;
	};

}