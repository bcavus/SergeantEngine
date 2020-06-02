#include "camera.h"

Camera::Camera(glm::vec3& camera_position, float field_of_view, float aspect_ratio, float zNear, float zFar)
{
	this->m_perspective = glm::perspective(field_of_view, aspect_ratio, zNear, zFar);
	this->m_camera_position = camera_position;
	this->m_camera_forward = glm::vec3(0, 0, -1);
	this->m_camera_up = glm::vec3(0, 1, 0);
}

Camera::~Camera()
{
}

void Camera::Init()
{
}

glm::mat4 Camera::ViewProjection() const
{
	return this->m_perspective * glm::lookAt(this->m_camera_position, this->m_camera_position * this->m_camera_forward, this->m_camera_up);;
}

