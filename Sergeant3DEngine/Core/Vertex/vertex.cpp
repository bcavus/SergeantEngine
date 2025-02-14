#include "vertex.h"

Vertex::Vertex(const glm::vec3 &position, const glm::vec2 &tex_coord, const glm::vec3& normal)
{
	this->m_position = position;
	this->m_tex_coord = tex_coord;
	this->m_normals = normal;
}

Vertex::~Vertex()
{
	//delete this;
}

const glm::vec3& Vertex::Position() const
{
	return this->m_position;
}

const glm::vec2& Vertex::TexCoord() const
{
	return this->m_tex_coord;
}

const glm::vec3& Vertex::Normal() const
{
	return this->m_normals;
}

