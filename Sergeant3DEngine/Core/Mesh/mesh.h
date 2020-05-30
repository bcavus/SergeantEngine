#include "GL/glew.h"
#include "../Vertex/vertex.h"

#ifndef  MESH_H
#define MESH_H

class Mesh {
public:
	Mesh(Vertex *vertices, unsigned int number_of_vertices);
	~Mesh();

	void Draw();
private:
	enum {
		Position_Vb,
		NUM_BUFFER
	};
	GLuint m_vertex_array_object;
	GLuint m_vertex_array_buffer[NUM_BUFFER];
	unsigned int m_draw_count;
};

#endif // ! MESH_H

