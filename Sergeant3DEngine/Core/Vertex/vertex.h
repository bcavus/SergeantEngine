#include <glm.hpp>

#ifndef  VERTEX_H
#define VERTEX_H

class Vertex {
public:
	Vertex(const glm::vec3 &position, const glm::vec2 &tex_coord);
	~Vertex();

	const glm::vec3 &Position() const;
	const glm::vec2 &TexCoord() const;

private:
	glm::vec3 m_position;
	glm::vec2 m_tex_coord;
};

#endif // ! VERTEX_H

