#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef WINDOW_H
#define WINDOW_H

class Window {
private:
	int m_close_flag;
	float m_aspectRatio;
	GLFWwindow* m_gl_window;

public:
	int m_height;
	int m_width;

private:
	void Init();
	void Dispose();

public:
	Window(int height, int width);
	~Window();

	void UpdateViewport();
	void SwapBuffers();
	void PollEvents();
	void Close();
	void Refresh();
	bool isOpen();
	void SetProperties(const int height, const int width);
	const float CalculateAspectRatio();
};

#endif