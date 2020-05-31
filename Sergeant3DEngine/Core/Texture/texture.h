
#include <string>
#include <iostream>
#include <cassert>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../External/stb_image/stb_image.h"

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
public:
	Texture(const std::string& file_name);
	~Texture();

	void Init(const std::string& image_file);
	void Dispose();
	void Bind(unsigned int texture_unit);

private:
	GLuint m_texture;
};
#endif // !TEXTURE_H
