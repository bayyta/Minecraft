#pragma once

#include "layer.h"
#include "../renderers/renderer3d.h"

namespace graphics {

	class Layer3D : public Layer
	{
	public:
		Layer3D(Shader* shader);
		void add(const Mesh* mesh, const Renderable* renderable);
		void render() override;
	};

}
