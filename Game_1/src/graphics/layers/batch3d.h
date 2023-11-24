#pragma once

#include "layer.h"
#include "../renderers/batchrenderer3d.h"

namespace graphics {

	class Batch3D : public Layer
	{
	public:
		Batch3D(Mesh* mesh, Shader* shader);
		void add(const Renderable* renderable);
		void render() override;
	};

}
