#version 330 core

in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D image;

void main()
{
    FragColor = texture(image, TexCoords);
    // FragColor = vec4(0.0f, 1.0f, 0.0f, 0.0f);
}