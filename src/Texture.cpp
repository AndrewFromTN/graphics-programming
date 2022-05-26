#include "Texture.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Texture::Texture(unsigned int texture_width, unsigned int texture_height, unsigned int texture_channels, unsigned char* texture_data)
{
    this->texture_width = texture_width;
    this->texture_height = texture_height;
    this->texture_channels = texture_channels;

    bind_texture(texture_data);
}

bool Texture::bind_texture(unsigned char* texture_data) 
{
    int channels = (texture_channels == 3) ? GL_RGB : GL_RGBA;

    glGenTextures(1, &texture);  
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, channels, texture_width, texture_height, 0, channels, GL_UNSIGNED_BYTE, texture_data);
    glGenerateMipmap(GL_TEXTURE_2D);

    return true;
}

unsigned int Texture::getTexture() const
{
    return texture;
}

Texture::~Texture()
{

}