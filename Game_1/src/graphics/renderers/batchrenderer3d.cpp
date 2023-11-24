#include "batchrenderer3d.h"

namespace graphics {

	BatchRenderer3D::BatchRenderer3D(Mesh* mesh)
		: m_Mesh(mesh)
	{
		init();
	}

	BatchRenderer3D::~BatchRenderer3D()
	{
		delete m_Mesh;
	}

	void BatchRenderer3D::init()
	{
		m_Mesh->getVAO()->bind();

		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(SHADER_OFFSET_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);
		glEnableVertexAttribArray(SHADER_TID_INDEX);

		glVertexAttribPointer(SHADER_OFFSET_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_INSTANCE_SIZE, (const GLvoid*)0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_INSTANCE_SIZE, (const GLvoid*)(offsetof(InstanceData, InstanceData::color)));
		glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, RENDERER_INSTANCE_SIZE, (const GLvoid*)(offsetof(InstanceData, InstanceData::tid)));

		glVertexAttribDivisor(SHADER_OFFSET_INDEX, 1);
		glVertexAttribDivisor(SHADER_COLOR_INDEX, 1);
		glVertexAttribDivisor(SHADER_TID_INDEX, 1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		m_Mesh->getVAO()->unbind();
	}

	void BatchRenderer3D::begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		m_Buffer = (InstanceData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void BatchRenderer3D::submit(const Renderable* renderable)
	{
		const GLuint tid = renderable->getTID();

		float ts = 0.0f;
		if (tid > 0)
		{
			bool found = false;
			for (int i = 0; i < m_TextureSlots.size(); i++)
			{
				if (m_TextureSlots[i] == tid)
				{
					ts = (float)(i + 1);
					found = true;
					break;
				}
			}

			if (!found)
			{
				if (m_TextureSlots.size() >= 32)
				{
					end();
					flush();
					begin();
				}
				m_TextureSlots.push_back(tid);
				ts = (float)(m_TextureSlots.size());
			}
		}

		m_Buffer->position = renderable->getPosition();
		m_Buffer->color = renderable->getColor();
		m_Buffer->tid = ts;

		m_Buffer++;
		m_Count++;
	}

	void BatchRenderer3D::end()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void BatchRenderer3D::flush()
	{
		for (int i = 0; i < m_TextureSlots.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, m_TextureSlots[i]);
		}

		m_Mesh->getVAO()->bind();
		m_Mesh->getIBO()->bind();

		glDrawElementsInstanced(GL_TRIANGLES, m_Mesh->getIBO()->getCount(), GL_UNSIGNED_INT, NULL, m_Count);

		m_Mesh->getIBO()->unbind();
		m_Mesh->getVAO()->unbind();

		m_Count = 0;
	}

}