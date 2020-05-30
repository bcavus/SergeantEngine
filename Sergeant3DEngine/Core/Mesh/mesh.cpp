#include "mesh.h"

Mesh::Mesh(Vertex *vertices, unsigned int number_of_vertices)
{
	m_draw_count = number_of_vertices;

	glGenVertexArrays(1, &m_vertex_array_object);
	glBindVertexArray(m_vertex_array_object);

	glGenBuffers(NUM_BUFFER, m_vertex_array_buffer);
	glBindBuffer(GL_ARRAY_BUFFER , m_vertex_array_buffer[Position_Vb]);
	glBufferData(GL_ARRAY_BUFFER, number_of_vertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDisableVertexAttribArray(0);
	glDeleteVertexArrays(1, &m_vertex_array_object);
	delete this;
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertex_array_object);

	glDrawArrays(GL_TRIANGLES, 0, m_draw_count);

	glBindVertexArray(0);
}
