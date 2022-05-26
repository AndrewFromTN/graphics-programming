#include "GameEntity.hpp"
#include "Component.hpp"
#include "Sprite.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <algorithm>
#include <iostream>
#include "stb_image.h"
#include <glm/gtc/matrix_transform.hpp>

GameEntity::GameEntity()
{

}

// ToDo: Rule of Three (Five)
GameEntity::GameEntity(const GameEntity& game_entity)
{

}

// ToDo(andrew): does every entity need a VAO?
GameEntity::GameEntity(const std::string& shader, float* vertices, int num_components, unsigned int texture_width, 
                       unsigned int texture_height, unsigned int texture_channels, unsigned char* texture_data)
{
    unsigned int indices[] = {
        0, 1, 2,
        1, 2, 3
    };

    moving = false;
    velocity = 0;
    direction_vector = glm::vec3(0);

    initialize_graphics(vertices, 1, indices, num_components, shader, texture_width, texture_height, texture_channels, texture_data);
}

void GameEntity::initialize_graphics(float* vertices, int num_rects, unsigned int* indices, int num_components, 
                                     const std::string& shader, unsigned int texture_width, unsigned int texture_height, 
                                     unsigned int texture_channels, unsigned char* texture_data)
{
    this->shader = shader;
    vertex_size = num_rects * 6;
    model_matrix = glm::mat4(1.0f);

    sprite = new Sprite(vertices, indices, num_rects, num_components, texture_width, texture_height, texture_channels, texture_data);
}

void GameEntity::move(const glm::vec3 &translate)
{
    direction_vector = translate;
    velocity = 1.0f;
    moving = true;
    //model_matrix = glm::translate(model_matrix, translate);
}

void GameEntity::update()
{
    if (moving)
    {
        model_matrix =  glm::translate(model_matrix, direction_vector * velocity);
    }

    for (const auto& kv : components) 
    {
        kv.second->execute(this);
    }
}

void GameEntity::render()
{
    EventsManager::Notify(Event::RENDER_MODEL, this);
}

void GameEntity::addComponent(Component* component)
{
    components[component->type] = component;
}

RenderComponent* GameEntity::getRenderComponent()
{
    return (RenderComponent*)components["Render"];
}

glm::mat4 GameEntity::getModelMatrix() const
{
    return model_matrix;
}

size_t GameEntity::getVertexSize() const
{
    return vertex_size;
}

unsigned int GameEntity::getVBO() const
{
    return (sprite != nullptr) ? sprite->getVBO() : 0;
}

unsigned int GameEntity::getVAO() const
{
    return (sprite != nullptr) ? sprite->getVAO() : 0;
}

unsigned int GameEntity::getTexture() const
{
    return (sprite != nullptr) ? sprite->getTexture() : 0;
}

std::string GameEntity::getShader() const
{
    return shader;
}

GameEntity::~GameEntity()
{
    delete sprite;
    sprite = nullptr;
}