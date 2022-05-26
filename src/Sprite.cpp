#include "Sprite.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Texture.hpp"

Sprite::Sprite(float* vertex_data, unsigned int* indices, int num_rects, int num_components, unsigned int texture_width, 
               unsigned int texture_height, unsigned int texture_channels, unsigned char* texture_data)
{
    this->vertex_data = vertex_data;
    this->indices = indices;
    this->num_components = num_components;
    this->num_rects = num_rects;

    init_render_data();

    texture = new Texture(texture_width, texture_height, texture_channels, texture_data);
}

void Sprite::init_render_data()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, num_rects * num_components * sizeof(float), vertex_data, GL_STATIC_DRAW);
    //glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(float), vertex_data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_components * 6 * sizeof(indices), indices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_rects * 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

unsigned int Sprite::getVAO() const
{
    return VAO;
}

unsigned int Sprite::getVBO() const
{
    return VBO;
}

unsigned int Sprite::getTexture() const
{
    return (texture != nullptr) ? texture->getTexture() : 0;
}

Sprite::~Sprite()
{
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &EBO);

    delete texture;
    texture = nullptr;
}

