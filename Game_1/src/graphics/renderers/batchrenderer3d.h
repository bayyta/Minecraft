#pragma once

#include "renderer.h"
#include "../renderables/renderable.h"
#include "../renderables/mesh.h"

namespace graphics {

#define RENDERER_MAX_OBJECTS	1000000
#define RENDERER_INSTANCE_SIZE	sizeof(InstanceData)
#define RENDERER_BUFFER_SIZE	RENDERER_INSTANCE_SIZE * RENDERER_MAX_OBJECTS

#define SHADER_OFFSET_INDEX 3
#define SHADER_COLOR_INDEX  4
#define SHADER_TID_INDEX    5

	struct InstanceData
	{
		glm::vec3 position;
		unsigned int color;
		float tid;
	};

	class BatchRenderer3D : public Renderer
	{
	private:
		unsigned int m_Count = 0;
		Mesh* m_Mesh;
		GLuint m_BufferID;
		InstanceData* m_Buffer;
		std::vector<GLuint> m_TextureSlots;
	public:
		BatchRenderer3D(Mesh* mesh);
		~BatchRenderer3D();
		void begin() override;
		void submit(const Renderable* renderable) override;
		void end() override;
		void flush() override;
	private:
		void init();
	};

}