#include <vector>
#include "GL/glew.h"
#include "../Vertex/vertex.h"

#ifndef  MESH_H
#define MESH_H

class Mesh {
public:
	Mesh(Vertex *vertices, unsigned int number_of_vertices);
	~Mesh();

	void Init(Vertex* vertices, unsigned int number_of_vertices);
	void Draw();
private:
	enum {
		Position_Vb,
		TexCoord_Vb,

		NUM_BUFFER
	};
	GLuint m_vertex_array_object;
	GLuint m_vertex_array_buffer[NUM_BUFFER];
	unsigned int m_draw_count;
};

#endif // ! MESH_H

