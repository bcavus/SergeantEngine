#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm.hpp"
#include "../Transform/transform.h"
#include "../Camera/camera.h"

#ifndef SHADER_H
#define SHADER_H

enum ShaderType {
	VertextShader = GL_VERTEX_SHADER,
	FragmentShader = GL_FRAGMENT_SHADER,
	GeometryShader = GL_GEOMETRY_SHADER,
	COUNT = 3,
};

enum UniformTypes {
	Transform_U,
	COUNT_U = 1,
};

class Shader {
public:
	Shader(const std::string& shader_file);
	~Shader();

	void Bind();
	void Dispose();
	void Init();
	void Update(const Transform& transform, const Camera& camera);
	GLuint CreateShader(const std::string& file_path, GLenum shader_type);

private:
	std::string LoadShader(const std::string& file_path);
	void CheckShaderError(GLuint shader, GLuint gl_flag, bool isProgram, const std::string& error_message);

private:
	GLuint m_program;
	GLuint m_shaders[ShaderType::COUNT];
	GLuint m_uniforms[UniformTypes::COUNT_U];

};

#endif