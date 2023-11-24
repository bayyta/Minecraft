#pragma once

#include <vector>
#include <GL/glew.h>

#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexarray.h"
#include "../../utils/glm.h"

namespace graphics {

	class Renderable;

	class Renderer
	{
	public:
		virtual void begin() {}
		virtual void submit(const Renderable* renderable) {}
		virtual void end() {}
		virtual void flush() = 0;
	};

}