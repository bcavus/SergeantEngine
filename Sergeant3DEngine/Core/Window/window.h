#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm.hpp"
#include "../Shader/shader.h"

#ifndef WINDOW_H
#define WINDOW_H

class Window {
private:
	float m_aspectRatio;

public:
	int m_height;
	int m_width;

private:
	void Draw(GLuint vertex_buffer, Shader *shader);

public:
	Window(int height, int width);
	~Window();

	void Init();
	void SetProperties(const int height, const int width);
	const float CalculateAspectRatio();
};

#endif