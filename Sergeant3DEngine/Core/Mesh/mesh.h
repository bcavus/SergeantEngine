#include <iostream>
#include <vector>
#include "GL/glew.h"
#include "../../External/obj_loader/obj_loader.h"
#include "../Vertex/vertex.h"

#ifndef  MESH_H
#define MESH_H

class Mesh {
public:
	Mesh(Vertex *vertices, unsigned int number_of_vertices, unsigned int* indices, unsigned int number_of_indices);
	Mesh(const std::string &filename);
	~Mesh();

	void Init(Vertex* vertices, unsigned int number_of_vertices, unsigned int* indices, unsigned int number_of_indices);
	void InitModel(const IndexedModel &model);
	void Draw();
private:
	enum {
		Position_Vb,
		TexCoord_Vb,
		Normal_Vb,
		Index_Vb,

		NUM_BUFFER
	};
	GLuint m_vertex_array_object;
	GLuint m_vertex_array_buffer[NUM_BUFFER];
	unsigned int m_draw_count;
};

#endif // ! MESH_H

