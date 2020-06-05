#include <glm.hpp>

#ifndef  VERTEX_H
#define VERTEX_H

class Vertex {
public:
	Vertex(const glm::vec3 &position, const glm::vec2 &tex_coord, const glm::vec3& normal);
	~Vertex();

	const glm::vec3 &Position() const;
	const glm::vec2 &TexCoord() const;
	const glm::vec3& Normal() const;

private:
	glm::vec3 m_position;
	glm::vec2 m_tex_coord;
	glm::vec3 m_normals;
};

#endif // ! VERTEX_H

