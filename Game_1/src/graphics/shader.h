#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../utils/glm.h"
#include "../utils/fileutils.h"

namespace graphics {

	class Shader
	{
	private:
		const char *m_VertPath, *m_FragPath;
	public:
		GLuint m_ShaderID;
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void setUniform1f(const char *name, float value);
		void setUniform1fv(const GLchar* name, float* value, int count);
		void setUniform1i(const char *name, GLuint value);
		void setUniform1iv(const GLchar* name, int* value, int count);
		void setUniform2f(const char *name, const glm::vec2& vector);
		void setUniform3f(const char *name, const glm::vec3& vector);
		void setUniform4f(const char *name, const glm::vec4& vector);
		void setUniformMat4(const char *name, const glm::mat4& matrix);

		void enable() const;
		void disable() const;
	private:
		GLuint load();
		GLint getUniformLocation(const GLchar *name);
	};

}