#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture_coordinate;

uniform mat4 transform;

out vec2 v_tex_coord;

void main()
{
  gl_Position = transform * vec4(position, 0.75);
  v_tex_coord = texture_coordinate;
};