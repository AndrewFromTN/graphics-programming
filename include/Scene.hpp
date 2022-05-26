#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <vector>
#include <glm/glm.hpp>

class Camera;
class GameEntity;

class Scene
{
    private:
        Camera* camera;

        std::vector<GameEntity*> entities;

        std::string name;
    public:
        Scene(const std::string& name);
        ~Scene();

        std::string get_name() const;
        glm::mat4 get_view() const;
        std::vector<GameEntity*> get_entities() const;
};

#endif