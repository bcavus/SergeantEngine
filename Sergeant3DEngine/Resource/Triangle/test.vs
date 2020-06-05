#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture_coordinate;
layout(location = 2) in vec3 normal;

uniform mat4 transform;

out vec2 v_tex_coord;
out vec3 v_normal;

void main()
{
  gl_Position = transform * vec4(position, 1.00);
  v_tex_coord = texture_coordinate;
  v_normal = (transform * vec4(normal, 0.00)).xyz;
};