#include "vertex.h"

Vertex::Vertex(const glm::vec3 &position)
{
	this->m_position = position;
}

Vertex::~Vertex()
{
	delete this;
}

