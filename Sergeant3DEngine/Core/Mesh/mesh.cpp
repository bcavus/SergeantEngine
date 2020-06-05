#include "mesh.h"
#include "mesh.h"
#include "mesh.h"

Mesh::Mesh(Vertex *vertices, unsigned int number_of_vertices, unsigned int* indices, unsigned int number_of_indices)
{
	m_draw_count = number_of_indices;
	this->Init(vertices, number_of_vertices, indices, number_of_indices);
}

Mesh::Mesh(const std::string& filename)
{
	this->InitModel(OBJModel(filename).ToIndexedModel());
}

Mesh::~Mesh()
{
	glDisableVertexAttribArray(0);
	glDeleteVertexArrays(1, &m_vertex_array_object);
	//delete this;
}

void Mesh::Init(Vertex* vertices, unsigned int number_of_vertices, unsigned int* indices, unsigned int number_of_indices)
{
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texture_coordinates;
	std::vector<glm::vec3> normals;

	IndexedModel model;

	for (unsigned int i = 0; i < number_of_vertices; i++) {
		model.positions.push_back(vertices[i].Position());
		model.texCoords.push_back(vertices[i].TexCoord());
		model.normals.push_back(vertices[i].Normal());
	}

	for (unsigned int i = 0; i < number_of_indices; i++) {
		model.indices.push_back(indices[i]);
	}

	this->InitModel(model);
	/*
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

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertex_array_buffer[Index_Vb]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, number_of_indices * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

		glBindVertexArray(0);
	*/
}

void Mesh::InitModel(const IndexedModel& model)
{
	this->m_draw_count = model.indices.size();

	glGenVertexArrays(1, &m_vertex_array_object);
	glBindVertexArray(m_vertex_array_object);

	glGenBuffers(NUM_BUFFER, m_vertex_array_buffer);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertex_array_buffer[Position_Vb]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertex_array_buffer[TexCoord_Vb]);
	glBufferData(GL_ARRAY_BUFFER, model.texCoords.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertex_array_buffer[Normal_Vb]);
	glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(model.normals[0]), &model.normals[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertex_array_buffer[Index_Vb]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertex_array_object);

	glDrawElements(GL_TRIANGLES,m_draw_count, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}
