// Sergeant3DEngine.cpp : Defines the entry point for the application.
//

#include "Sergeant3DEngine.h"
#include "Core/Window/Window.h"

using namespace std;

int main()
{
	const int screen_height = 480, screen_width = 640;

	Window* window = new Window(screen_height, screen_width);

	cout << "Window Properties Updated : " << window->m_height << " - " << window->m_width << endl;

	window->Init();

	cout << "Window Initialized." << endl;

	return 0;
}
