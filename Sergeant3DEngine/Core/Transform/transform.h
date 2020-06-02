#include <glm.hpp>
#include <gtx/transform.hpp>

#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform {
public:
	Transform(glm::vec3& position, glm::vec3& rotation, glm::vec3& scale);
	~Transform();

	glm::mat4 TransformModel() const;

	void SetPosition(const glm::vec3& position);
	void SetRotation(const glm::vec3& rotation);
	void SetScale(const glm::vec3& scale);

	const glm::vec3& Position() const;
	const glm::vec3& Rotation() const;
	const glm::vec3& Scale() const;

private:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;

};
#endif // !TRANSFORM_H
