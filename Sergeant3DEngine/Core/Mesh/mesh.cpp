#include "mesh.h"

Mesh::Mesh(Vertex *vertices, unsigned int number_of_vertices)
{
	m_draw_count = number_of_vertices;
	this->Init(vertices, number_of_vertices);
}

Mesh::~Mesh()
{
	glDisableVertexAttribArray(0);
	glDeleteVertexArrays(1, &m_vertex_array_object);
	delete this;
}

void Mesh::Init(Vertex* vertices, unsigned int number_of_vertices)
{
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texture_coordinates;

	positions.reserve(number_of_vertices);
	texture_coordinates.reserve(number_of_vertices);

	for (unsigned int i = 0; i < number_of_vertices; i++) {
		positions.push_back(vertices[i].Position());
		texture_coordinates.push_back(vertices[i].TexCoord());
	}

	glGenVertexArrays(1, &m_vertex_array_object);
	glBindVertexArray(m_vertex_array_object);

	glGenBuffers(NUM_BUFFER, m_vertex_array_buffer);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertex_array_buffer[Position_Vb]);
	glBufferData(GL_ARRAY_BUFFER, number_of_vertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertex_array_buffer[TexCoord_Vb]);
	glBufferData(GL_ARRAY_BUFFER, number_of_vertices * sizeof(texture_coordinates[0]), &texture_coordinates[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertex_array_object);

	glDrawArrays(GL_TRIANGLES, 0, m_draw_count);

	glBindVertexArray(0);
}
