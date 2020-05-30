#include "window.h"

Window::Window(int height, int width) {
	Window::SetProperties(height, width);
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

	GLFWwindow* gl_window = glfwCreateWindow(this->m_width, this->m_height, "GL Window", NULL, NULL);

	if (!gl_window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(gl_window);
	glewExperimental = true;
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		printf("Failed to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}

	GLuint vertex_array_objectID;
	glGenVertexArrays(1, &vertex_array_objectID);
	glBindVertexArray(vertex_array_objectID);

	static const GLfloat gl_vertext_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	GLuint vertex_buffer;

	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(gl_vertext_buffer_data), gl_vertext_buffer_data, GL_STATIC_DRAW);

	Shader *simple_shader = new Shader("../../../Resource/Triangle/test"); //TODO: ResourceManager
	
	while (!glfwWindowShouldClose(gl_window)) {
		this->m_aspectRatio = this->CalculateAspectRatio();

		/*
			- Preparing View
		*/
		glfwGetFramebufferSize(gl_window, &this->m_width, &this->m_height);
		glViewport(0, 0, this->m_width, this->m_height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*
			- Draw 
		*/
		this->Draw(vertex_buffer, simple_shader);

		/*
			- Swapping Buffers
		*/
		glfwSwapBuffers(gl_window);
		
		/*
			- Handle Events
		*/

		glfwPollEvents();
	}

	delete simple_shader;

	glfwDestroyWindow(gl_window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void Window::Draw(GLuint vertex_buffer, Shader *shader) {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

	shader->Bind();
}

void Window::SetProperties(int height, int width) {
	this->m_height = height;
	this->m_width = width;
}

const float Window::CalculateAspectRatio()
{
	if (this->m_height && this->m_width && this->m_height > 0 && this->m_width > 0) {
		return (float)(this->m_width / this->m_height);
	}

	return 0.0f;
}

