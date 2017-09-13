#version 330 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 texCoordsOut;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 0.0f, 1.0f);

	texCoordsOut = texCoords;
}