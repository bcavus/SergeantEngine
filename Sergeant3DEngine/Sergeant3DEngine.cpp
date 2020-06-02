// Sergeant3DEngine.cpp : Defines the entry point for the application.
//

#include "Sergeant3DEngine.h"
#include "Core/Window/Window.h"
#include "Core/Vertex/vertex.h"
#include "Core/Shader/shader.h"
#include "Core/Texture/texture.h"
#include "Core/Mesh/mesh.h"
#include "Core/Transform/transform.h"

using namespace std;

int main()
{
	const int screen_height = 480, screen_width = 640;

	Window* window = new Window(screen_height, screen_width);

	cout << "Window Properties Updated : " << window->m_height << " - " << window->m_width << endl;

	cout << "Window Initialized." << endl;

	Vertex triangle_vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 0)),
		Vertex(glm::vec3(0, 0.5, 0), glm::vec2(1.0, 0)),
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 1.0)),
	};

	Shader triangle_shader("../../../Resource/Triangle/test");

	Texture triangle_texture("../../../Resource/Textures/test.jpg");

	Mesh triangle_mesh(triangle_vertices, sizeof(triangle_vertices) / sizeof(triangle_vertices[0]));

	Transform transform(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1,1,1));

	float transform_counter = 0.0f;

	while (window->isOpen()) {

		window->UpdateViewport();
		window->Refresh();

		triangle_shader.Bind();
		
		transform.SetPosition(glm::vec3(cosf(transform_counter), cosf(transform_counter), cosf(transform_counter)));
		transform.SetRotation(glm::vec3(cosf(transform_counter), cosf(transform_counter), cosf(transform_counter)));
		transform.SetScale(glm::vec3(cosf(transform_counter * 1.5f)));

		triangle_shader.Update(transform);

		triangle_texture.Bind(0);
		triangle_mesh.Draw();

		transform_counter += 0.01f;

		window->SwapBuffers();
		window->PollEvents();
	}

	window->Close();

	return 0;
}
