#include "layer3d.h"

namespace graphics {

	Layer3D::Layer3D(Shader* shader)
		: Layer(new Renderer3D(), shader)
	{ }

	void Layer3D::add(const Mesh* mesh, const Renderable* renderable)
	{
		m_Meshes.push_back(mesh);
		m_Renderables.push_back(renderable);
	}

	void Layer3D::render()
	{
		m_Shader->enable();

		for (int i = 0; i < m_Renderables.size(); i++)
		{
			m_Shader->setUniformMat4("ml_matrix", glm::translate(glm::mat4(1.0f), m_Renderables[i]->getPosition()));
			((Renderer3D*) m_Renderer)->submit(m_Meshes[i], m_Renderables[i]);
		}

		m_Renderer->flush();

		m_Shader->disable();
	}

}