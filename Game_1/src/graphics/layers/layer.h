#pragma once

#include "../renderers/renderer.h"
#include "../renderables/renderable.h"
#include "../renderables/mesh.h"

namespace graphics {

	class Layer
	{
	protected:
		Renderer* m_Renderer;
		Shader* m_Shader;
		std::vector<const Mesh*> m_Meshes;
		std::vector<const Renderable*> m_Renderables;
	protected:
		Layer(Renderer* renderer, Shader* shader)
			: m_Renderer(renderer), m_Shader(shader)
		{ }
	public:
		virtual ~Layer()
		{
			delete m_Renderer;
			delete m_Shader;
			for (const Mesh* mesh : m_Meshes)
				delete mesh;
			for (const Renderable* renderable : m_Renderables)
				delete renderable;
		}
		virtual void render() = 0;

		inline const std::vector<const Renderable*>& getRenderables() const { return m_Renderables; }
	};

}
