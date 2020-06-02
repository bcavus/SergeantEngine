#include <iostream>
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtx/string_cast.hpp>

#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
	Camera(glm::vec3& camera_position, float field_of_view, float aspect_ratio, float zNear, float zFar);
	~Camera();

	void Init();
	glm::mat4 ViewProjection() const;

private:
	glm::mat4 m_perspective;
	glm::vec3 m_camera_position;
	glm::vec3 m_camera_forward;
	glm::vec3 m_camera_up;
};

#endif // !CAMERA_H
