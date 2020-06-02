#include "transform.h"

Transform::Transform(glm::vec3& position, glm::vec3& rotation, glm::vec3& scale)
{
	this->m_position = position;
	this->m_rotation = rotation;
	this->m_scale = scale;
}

Transform::~Transform()
{
	delete this;
}

glm::mat4 Transform::TransformModel() const
{
	glm::mat4 position_matrix = glm::translate(this->m_position);

	glm::mat4 rotation_x_matrix = glm::rotate(this->m_rotation.x, glm::vec3(1.0, 0.0, 0.0));
	glm::mat4 rotation_y_matrix = glm::rotate(this->m_rotation.y, glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 rotation_z_matrix = glm::rotate(this->m_rotation.z, glm::vec3(0.0, 0.0, 1.0));
	
	glm::mat4 rotation_matrix = rotation_z_matrix * rotation_y_matrix * rotation_x_matrix;

	glm::mat4 scale_matrix = glm::scale(this->m_scale);

	return position_matrix * rotation_matrix * scale_matrix;
}

void Transform::SetPosition(const glm::vec3& position)
{
	this->m_position = position;
}

void Transform::SetRotation(const glm::vec3& rotation)
{
	this->m_rotation = rotation;
}

void Transform::SetScale(const glm::vec3& scale)
{
	this->m_scale = scale;
}

const glm::vec3& Transform::Position() const
{
	return this->m_position;
}

const glm::vec3& Transform::Rotation() const
{
	return this->m_rotation;
}

const glm::vec3& Transform::Scale() const
{
	return this->m_scale;
}
