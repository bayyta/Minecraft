#pragma once

#include "../buffers/vertexarray.h"

#include "../renderers/renderer.h"
#include "../texture.h"

#include "../../utils/glm.h"
#include "../shader.h"

namespace graphics {

	class Renderable
	{
	private:
		glm::vec3 m_Position;
		unsigned int m_Color;
		Texture* m_Texture;
	public:
		Renderable(glm::vec3 position, unsigned int color)
			: m_Position(position), m_Color(color), m_Texture(nullptr)
		{ }

		Renderable(glm::vec3 position, Texture* texture)
			: m_Position(position), m_Color(0), m_Texture(texture)
		{ }

		~Renderable()
		{ }

		void setPosition(glm::vec3 position)
		{
			m_Position = position;
		}

		inline const glm::vec3& getPosition() const { return m_Position; }
		inline const unsigned int& getColor() const { return m_Color; }
		inline Texture* getTexture() const { return m_Texture; }
		inline const GLuint getTID() const { return m_Texture ? m_Texture->getID() : 0; }
	};

}