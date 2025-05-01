#include "common/texture.h"

Texture::Texture() {}

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType, GLenum internalFormat = GL_RGBA, bool shouldFlip = false) {
    type = texType;
    int imageWidth, imageHeight, totalColorchannels;
	stbi_set_flip_vertically_on_load(shouldFlip);
	unsigned char* imageBytes = stbi_load(image, &imageWidth, &imageHeight, &totalColorchannels, STBI_rgb_alpha);

	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(texType, ID);
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(texType, 0, internalFormat, imageWidth, imageHeight, 0, format, pixelType, imageBytes);
	glGenerateMipmap(texType);

	stbi_image_free(imageBytes);
	Unbind();
};

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit) {
    GLuint tex0Uniform = glGetUniformLocation(shader.ID, uniform);
    shader.Use();
    glUniform1f(tex0Uniform, unit);
};

void Texture::Bind() {
    glBindTexture(type, ID);
};

void Texture::Unbind() {
    glBindTexture(type, 0);
};

void Texture::Delete() {
    glDeleteTextures(1, &ID);
}