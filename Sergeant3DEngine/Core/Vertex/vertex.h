#include <glm.hpp>

#ifndef  VERTEX_H
#define VERTEX_H

class Vertex {
public:
	Vertex(const glm::vec3 &position);
	~Vertex();

private:
	glm::vec3 m_position;
};

#endif // ! VERTEX_H

