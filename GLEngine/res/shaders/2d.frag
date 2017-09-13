#version 330 core

in vec2 texCoordsOut;

uniform vec4 color;
uniform sampler2D tex;

out vec4 fragColor;

void main()
{
	fragColor = texture(tex, texCoordsOut);
}