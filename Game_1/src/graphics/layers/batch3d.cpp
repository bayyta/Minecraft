#pragma once

#include "batch3d.h"

namespace graphics {

	Batch3D::Batch3D(Mesh* mesh, Shader* shader)
		: Layer(new BatchRenderer3D(mesh), shader)
	{ }

	void Batch3D::add(const Renderable* renderable)
	{
		m_Renderables.push_back(renderable);
	}

	void Batch3D::render()
	{
		m_Shader->enable();

		m_Renderer->begin();
		for (const Renderable* renderable : m_Renderables)
			m_Renderer->submit(renderable);
		m_Renderer->end();
		m_Renderer->flush();

		m_Shader->disable();
	}

}
