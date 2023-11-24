#include "block.h"

namespace graphics {

	Block::Block(glm::vec3 size)
		: m_Size(size)
	{
		init();
	}

	void Block::init()
	{
		GLfloat vertices[6 * 4 * 3] = {
			// Front
			-m_Size.x / 2.0f, -m_Size.y / 2.0f,  m_Size.z / 2.0f, // 0
			m_Size.x / 2.0f, -m_Size.y / 2.0f,  m_Size.z / 2.0f,  // 1
			m_Size.x / 2.0f,  m_Size.y / 2.0f,  m_Size.z / 2.0f,  // 2
			-m_Size.x / 2.0f,  m_Size.y / 2.0f,  m_Size.z / 2.0f, // 3

																  // Back
			-m_Size.x / 2.0f, -m_Size.y / 2.0f, -m_Size.z / 2.0f, // 4
			-m_Size.x / 2.0f,  m_Size.y / 2.0f, -m_Size.z / 2.0f, // 5
			m_Size.x / 2.0f,  m_Size.y / 2.0f, -m_Size.z / 2.0f,  // 6
			m_Size.x / 2.0f, -m_Size.y / 2.0f, -m_Size.z / 2.0f,  // 7

																  // Top
			-m_Size.x / 2.0f,  m_Size.y / 2.0f, -m_Size.z / 2.0f, // 8
			-m_Size.x / 2.0f,  m_Size.y / 2.0f,  m_Size.z / 2.0f, // 11
			m_Size.x / 2.0f,  m_Size.y / 2.0f,  m_Size.z / 2.0f,  // 10
			m_Size.x / 2.0f,  m_Size.y / 2.0f, -m_Size.z / 2.0f,  // 9

																  // Bottom
			-m_Size.x / 2.0f, -m_Size.y / 2.0f, -m_Size.z / 2.0f, // 12
			m_Size.x / 2.0f, -m_Size.y / 2.0f, -m_Size.z / 2.0f,  // 13
			m_Size.x / 2.0f, -m_Size.y / 2.0f,  m_Size.z / 2.0f,  // 14
			-m_Size.x / 2.0f, -m_Size.y / 2.0f,  m_Size.z / 2.0f, // 15

																  // Left
			-m_Size.x / 2.0f, -m_Size.y / 2.0f, -m_Size.z / 2.0f, // 16
			-m_Size.x / 2.0f, -m_Size.y / 2.0f,  m_Size.z / 2.0f, // 17
			-m_Size.x / 2.0f,  m_Size.y / 2.0f,  m_Size.z / 2.0f, // 18
			-m_Size.x / 2.0f,  m_Size.y / 2.0f, -m_Size.z / 2.0f, // 19

																  // Right
			m_Size.x / 2.0f, -m_Size.y / 2.0f, -m_Size.z / 2.0f,  // 20
			m_Size.x / 2.0f,  m_Size.y / 2.0f, -m_Size.z / 2.0f,  // 23
			m_Size.x / 2.0f,  m_Size.y / 2.0f,  m_Size.z / 2.0f,  // 22
			m_Size.x / 2.0f, -m_Size.y / 2.0f,  m_Size.z / 2.0f   // 21
		};

		GLuint indices[6 * 6] = {
			0,  1,  2,  2,  3,  0,  // Front
			4,  5,  6,  6,  7,  4,  // Back
			8,  9, 10, 10, 11,  8,  // Top
			12, 13, 14, 14, 15, 12, // Bottom
			16, 17, 18, 18, 19, 16, // Left
			20, 21, 22, 22, 23, 20  // Right
		};

		GLfloat normals[6 * 4 * 3] = {
			// Front
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,

			// Back
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,

			// Top
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,

			// Bottom
			0.0f, -1.0f,  0.0f,
			0.0f, -1.0f,  0.0f,
			0.0f, -1.0f,  0.0f,
			0.0f, -1.0f,  0.0f,

			// Left
			-1.0f,  0.0f,  0.0f,
			-1.0f,  0.0f,  0.0f,
			-1.0f,  0.0f,  0.0f,
			-1.0f,  0.0f,  0.0f,

			// Right
			1.0f,  0.0f,  0.0f,
			1.0f,  0.0f,  0.0f,
			1.0f,  0.0f,  0.0f,
			1.0f,  0.0f,  0.0f
		};

		GLfloat tcs[6 * 4 * 2] = {
			// front
			0.0f, 1.0f / 3.0f,
			0.5f, 1.0f / 3.0f,
			0.5f, 2.0f / 3.0f,
			0.0f, 2.0f / 3.0f,

			// back
			0.5f, 0.0f / 3.0f,
			0.5f, 1.0f / 3.0f,
			0.0f, 1.0f / 3.0f,
			0.0f, 0.0f / 3.0f,

			// top
			0.0f, 2.0f / 3.0f,
			0.5f, 2.0f / 3.0f,
			0.5f, 3.0f / 3.0f,
			0.0f, 3.0f / 3.0f,

			// bottom
			0.5f, 2.0f / 3.0f,
			1.0f, 2.0f / 3.0f,
			1.0f, 3.0f / 3.0f,
			0.5f, 3.0f / 3.0f,

			// left
			0.5f, 1.0f / 3.0f,
			1.0f, 1.0f / 3.0f,
			1.0f, 2.0f / 3.0f,
			0.5f, 2.0f / 3.0f,

			// right
			1.0f, 0.0f / 3.0f,
			1.0f, 1.0f / 3.0f,
			0.5f, 1.0f / 3.0f,
			0.5f, 0.0f / 3.0f
		};

		m_VBO = new Buffer(vertices, 6 * 4 * 3, 3);
		m_IBO = new IndexBuffer(indices, 6 * 6);
		m_NBO = new Buffer(normals, 6 * 4 * 3, 3);
		m_TBO = new Buffer(tcs, 6 * 4 * 2, 2);

		m_VAO = new VertexArray();
		m_VAO->addBuffer(m_VBO, 0);
		m_VAO->addBuffer(m_NBO, 1);
		m_VAO->addBuffer(m_TBO, 2);
	}

}