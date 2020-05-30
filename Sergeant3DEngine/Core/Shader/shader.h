#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm.hpp"

#ifndef SHADER_H
#define SHADER_H

enum ShaderType {
	VertextShader = GL_VERTEX_SHADER,
	FragmentShader = GL_FRAGMENT_SHADER,
	GeometryShader = GL_GEOMETRY_SHADER,
	COUNT = 3,
};

class Shader {
public:
	Shader(const std::string& shader_file);
	~Shader();

	void Bind();
	void Dispose();
	void Init();
	GLuint CreateShader(const std::string& file_path, GLenum shader_type);

private:
	std::string LoadShader(const std::string& file_path);
	void CheckShaderError(GLuint shader, GLuint gl_flag, bool isProgram, const std::string& error_message);

private:
	GLuint m_program;
	GLuint m_shaders[ShaderType::COUNT];

};

#endif