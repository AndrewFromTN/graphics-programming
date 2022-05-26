#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "EventsManager.hpp"

class Component;
class RenderComponent;
class Sprite;

class GameEntity
{
    protected:
        void initialize_graphics(float* vertices, int num_rect, unsigned int* indices, int num_components, const std::string& shader, 
                                 unsigned int texture_width, unsigned int texture_height, unsigned int texture_channels, unsigned char* texture_data);

        std::map<std::string, Component*> components;
        glm::mat4 model_matrix;   
        size_t vertex_size;
        std::string shader;
        Sprite* sprite;
        float velocity;
        glm::vec3 direction_vector;
        bool moving;

        GameEntity();

    public:
        GameEntity(const std::string& shader, float* vertices, int num_components, unsigned int texture_width, 
                   unsigned int texture_height, unsigned int texture_channels, unsigned char* texture_data);
        GameEntity(const GameEntity& game_entity);
        virtual ~GameEntity();

        virtual void update();
        virtual void render();

        virtual void move(const glm::vec3 &translate);

        void addComponent(Component* component);
        RenderComponent* getRenderComponent();

        glm::mat4 getModelMatrix() const;
        unsigned int getVBO() const;
        unsigned int getVAO() const;
        unsigned int getTexture() const;
        size_t getVertexSize() const;
        std::string getShader() const;
};

#endif