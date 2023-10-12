#version 330 core

layout (location = 0) in vec3 aPos;
uniform float u_Color;

out vec4 v_Color;

void main()
{
   v_Color = vec4(u_Color, 0.0f, 0.0f, 1.0f);
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}