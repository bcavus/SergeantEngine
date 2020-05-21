#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm.hpp"

#ifndef SHADER_H
#define SHADER_H

class Shader {
public:
	Shader();
	~Shader();
	
	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
};

#endif