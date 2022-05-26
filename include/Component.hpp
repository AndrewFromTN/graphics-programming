#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class GameEntity;

class Component
{
    public:
        virtual ~Component() {}
        virtual void execute(GameEntity* e) = 0;

        std::string type;
};

class RenderComponent : public Component
{
    public:
        RenderComponent(const std::string& shader, float* render_coords);

        virtual void execute(GameEntity* e) override;

        unsigned int VAO;
        unsigned int VBO;

        std::string shader;

        float* render_coords;
};

#endif