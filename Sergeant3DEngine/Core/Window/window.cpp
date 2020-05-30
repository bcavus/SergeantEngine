#include "window.h"

Window::Window(int height, int width) {
	this->SetProperties(height, width);
	this->Init();
}

Window::~Window() {
	delete this;
}

void Window::Init()
{
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	this->m_gl_window = glfwCreateWindow(this->m_width, this->m_height, "Sergeant3DEngine Window", NULL, NULL);

	if (!this->m_gl_window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->m_gl_window);
	glewExperimental = true;
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		printf("Failed to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}

	this->m_close_flag = false;
}

void Window::Dispose()
{
	glfwDestroyWindow(this->m_gl_window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void Window::Update()
{
	while (!glfwWindowShouldClose(this->m_gl_window)) {
		/*
			- Preparing View
		*/
		glfwGetFramebufferSize(this->m_gl_window, &this->m_width, &this->m_height);
		glViewport(0, 0, this->m_width, this->m_height);

		/*
			- Swapping Buffers
		*/
		glfwSwapBuffers(this->m_gl_window);

		/*
			- Handle Events
		*/

		glfwPollEvents();
	}
}

void Window::Close()
{
	this->m_close_flag = true;
}

void Window::Refresh()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Window::isOpen()
{
	return !this->m_close_flag;
}

void Window::SetProperties(int height, int width) {
	this->m_height = height;
	this->m_width = width;
	this->m_aspectRatio = this->CalculateAspectRatio();
}

const float Window::CalculateAspectRatio()
{
	if (this->m_height && this->m_width && this->m_height > 0 && this->m_width > 0) {
		return (float)(this->m_width / this->m_height);
	}

	return 0.0f;
}

