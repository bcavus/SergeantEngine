// Sergeant3DEngine.cpp : Defines the entry point for the application.
//

#include "Sergeant3DEngine.h"
#include "Core/Window/Window.h"
#include "Core/Vertex/vertex.h"
#include "Core/Shader/shader.h"
#include "Core/Texture/texture.h"
#include "Core/Mesh/mesh.h"
#include "Core/Transform/transform.h"
#include "Core/Camera/camera.h"

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

	unsigned int indices[] = { 0, 1, 2 };

	Shader triangle_shader("../../../Resource/Triangle/test");

	Texture triangle_texture("../../../Resource/Textures/multi-color.jpg");

	Mesh triangle_mesh(triangle_vertices, sizeof(triangle_vertices) / sizeof(triangle_vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));

	Transform transform(glm::vec3(0, 0, 0), glm::vec3(0, 0.5, 0.5), glm::vec3(1, 1, 1));

	Camera camera(glm::vec3(1.0f, 0.0f, 9.0f), 100.0f, 16.0 / 9.0, 0.01f, 1000.0f);
	
	Mesh test_3d_mesh("../../../Resource/Meshes/monkey3.obj");

	float transform_counter = 0.0f;

	while (window->isOpen()) {

		window->UpdateViewport();
		window->Refresh();

		triangle_shader.Bind();
		
		transform.SetPosition(glm::vec3(sinf(transform_counter), sinf(transform_counter * 0.4), sinf(transform_counter)));
		transform.SetRotation(glm::vec3(sinf(transform_counter * 0.1), sinf(transform_counter * 0.5), sinf(transform_counter)));
		transform.SetScale(glm::vec3(1.6, 1.6, 1.6));

		triangle_shader.Update(transform, camera);

		triangle_texture.Bind(0);
		//triangle_mesh.Draw();
		test_3d_mesh.Draw();

		transform_counter += 0.01f;

		window->SwapBuffers();
		window->PollEvents();
	}

	window->Close();

	return 0;
}
