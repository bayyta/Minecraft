#pragma once

#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexarray.h"

#include "../../utils/glm.h"

namespace graphics {

	class Mesh
	{
	protected:
		Buffer* m_VBO;
		IndexBuffer* m_IBO;
		Buffer* m_NBO;
		Buffer* m_TBO;
		VertexArray* m_VAO;
	public:
		inline Buffer* getVBO() const { return m_VBO; }
		inline IndexBuffer* getIBO() const { return m_IBO; }
		inline Buffer* getNBO() const { return m_NBO; }
		inline Buffer* getTBO() const { return m_TBO; }
		inline VertexArray* getVAO() const { return m_VAO; }
	};

}