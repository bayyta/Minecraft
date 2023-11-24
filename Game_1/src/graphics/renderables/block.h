#pragma once

#include "../renderables/mesh.h"

namespace graphics {

	class Block : public Mesh
	{
	private:
		glm::vec3 m_Size;
	public:
		Block(glm::vec3 size);
		inline const glm::vec3& getSize() const { return m_Size; }
	private:
		void init();
	};

}