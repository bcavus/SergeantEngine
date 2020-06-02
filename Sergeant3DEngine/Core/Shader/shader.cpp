#include "shader.h"
#include "shader.h"

Shader::Shader(const std::string& shader_file) {
	this->m_program = glCreateProgram();
	this->m_shaders[0] = CreateShader(LoadShader(shader_file + ".vs"), ShaderType::VertextShader);
	this->m_shaders[1] = CreateShader(LoadShader(shader_file + ".fs"), ShaderType::FragmentShader);
	this->m_shaders[2] = NULL;
	//m_shaders[2] = CreateShader(LoadShader(shader_file + ".gs"), ShaderType::GeometryShader);
	
	this->Init();
}

Shader::~Shader()
{
	this->Dispose();

	//delete this;
}

void Shader::Init()
{
	for (unsigned int i = 0; i < sizeof(this->m_shaders) / this->m_shaders[0]; i++) {
		glAttachShader(this->m_program, this->m_shaders[i]);
	}

	glBindAttribLocation(this->m_program, 0, "position");
	glBindAttribLocation(this->m_program, 1, "texture_coordinate");

	glLinkProgram(this->m_program);
	CheckShaderError(this->m_program, GL_LINK_STATUS, true, "[Shader] Program Link FAILED!");

	glValidateProgram(this->m_program);
	CheckShaderError(this->m_program, GL_VALIDATE_STATUS, true, "[Shader] Program Validation FAILED!");

	this->m_uniforms[UniformTypes::Transform_U] = glGetUniformLocation(this->m_program, "transform");
}

void Shader::Update(const Transform& transform)
{
	glm::mat4 transform_model = transform.TransformModel();

	glUniformMatrix4fv(this->m_uniforms[Transform_U], 1, GL_FALSE, &transform_model[0][0]);
}

void Shader::Dispose()
{
	for (unsigned int i = 0; i < sizeof(this->m_shaders) / this->m_shaders[0]; i++) {
		if (this->m_shaders[i] != NULL) {
			glDetachShader(this->m_program, this->m_shaders[i]);
			glDeleteShader(this->m_shaders[i]);
		}
	}

	glDeleteProgram(this->m_program);
}

void Shader::Bind()
{
	glUseProgram(this->m_program);
}

GLuint Shader::CreateShader(const std::string& file_path, GLenum shader_type)
{
	GLuint shader = glCreateShader(shader_type);

	if (shader == 0) {
		std::cerr << "[Shader]: Shader Creation Failed!";
	}

	const GLchar* shader_source[1];
	GLint shader_source_len[1];

	shader_source[0] = file_path.c_str();
	shader_source_len[0] = file_path.length();

	glShaderSource(shader, 1, shader_source, shader_source_len);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "[Shader] Shader Compilation FAILED!");
	
	return shader;
}

void Shader::CheckShaderError(GLuint shader, GLuint gl_flag, bool isProgram, const std::string& error_message)
{
	GLint gl_err_code = 0;
	GLchar error[1024] = { 0 };

	if (isProgram) {
		glGetProgramiv(shader, gl_flag, &gl_err_code);
	}
	else {
		glGetShaderiv(shader, gl_flag, &gl_err_code);
	}

	if (gl_err_code == GL_FALSE) {
		if (isProgram) {
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		}
		else {
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}

		std::cerr << error_message << ": '" << error << "'" << std::endl;
	}
}

std::string Shader::LoadShader(const std::string& file_path) {
	std::ifstream file;
	
	file.open((file_path).c_str());

	if (!file.is_open()) {
		std::cerr << "[Shader] Unable to open shader file." << file_path << std::endl;
	}

	std::string output;
	std::string line;

	while (file.good()) {
		getline(file, line);
		output.append(line + "\n");
	}

	return output;
}

