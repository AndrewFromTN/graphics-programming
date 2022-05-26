#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <string>
#include <vector>
#include <glm/glm.hpp>

class Scene;

class SceneManager
{
    private:
        Scene* current_scene;
        
        std::vector<Scene*> scenes;

        std::vector<Scene*>::iterator find_scene(const std::string& scene_name);
        std::vector<Scene*>::iterator find_scene(Scene* scene_name);
    public:
        SceneManager();
        ~SceneManager();

        void update();
        void add_to_render_queue();

        glm::mat4 get_view() const;

        // ToDo(andrew): Create an asynchronous version of allocate_scene
        void allocate_scene(const std::string& scene_name);
        void deallocate_scene(const std::string& scene_name);
        void deallocate_scene(Scene* scene);
        bool change_scene(Scene* scene);
        bool change_scene(const std::string& scene_name);
};

#endif