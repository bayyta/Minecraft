#include "renderer3d.h"

namespace graphics {

	void Renderer3D::submit(const Mesh* mesh, const Renderable* renderable)
	{
		m_Meshes.push_back(mesh);
		m_Renderables.push_back(renderable);
	}

	void Renderer3D::flush()
	{
		glActiveTexture(GL_TEXTURE0);
		for (int i = 0; i < m_Renderables.size(); i++)
		{
			const Mesh* mesh = m_Meshes[i];
			const Renderable* renderable = m_Renderables[i];

			mesh->getVAO()->bind();
			mesh->getIBO()->bind();
			renderable->getTexture()->bind();

			glDrawElements(GL_TRIANGLES, mesh->getIBO()->getCount(), GL_UNSIGNED_INT, NULL);

			renderable->getTexture()->unbind();
			mesh->getIBO()->bind();
			mesh->getVAO()->unbind();
		}

		m_Meshes.clear();
		m_Renderables.clear();
	}

}