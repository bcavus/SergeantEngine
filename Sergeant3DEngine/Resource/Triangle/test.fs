#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_tex_coord;
in vec3 v_normal;

uniform vec4 u_color;
uniform sampler2D u_texture;

void main()
{
  color = texture(u_texture, v_tex_coord)
  * clamp(dot(-vec3(0 ,0 ,1), v_normal), 0.0, 1.0);
};