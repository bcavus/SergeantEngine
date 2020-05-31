#include "texture.h"

Texture::Texture(const std::string& file_name)
{
	this->Init(file_name);
}

Texture::~Texture()
{
	this->Dispose();
	delete this;
}

void Texture::Init(const std::string& image_file)
{
	int width, height, num_components;
	void* image_data = stbi_load(image_file.c_str(), &width, &height, &num_components, 4);

	if (image_data == NULL) {
		std::cerr << "[Texture] Texture Loading FAILED!" << std::endl;
	}
	
	glGenTextures(1, &this->m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
	
	stbi_image_free(image_data);
}

void Texture::Dispose()
{
	glDeleteTextures(1, &this->m_texture);
}

void Texture::Bind(unsigned int texture_unit)
{
	assert(texture_unit >= 0 && texture_unit <= 31); //OPENGL valid texture loading check

	glActiveTexture(GL_TEXTURE0 + texture_unit);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}
