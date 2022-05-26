#include "SceneManager.hpp"
#include "Component.hpp"
#include "GameEntity.hpp"
#include <algorithm>
#include <iostream>
#include "Scene.hpp"
#include "LoggingService.hpp"

SceneManager::SceneManager()
{
    scenes.push_back(new Scene("Test Scene 0"));
    scenes.push_back(new Scene("Test Scene 1"));
    current_scene = scenes.at(0);
}

void SceneManager::update()
{
    std::vector<GameEntity*> entities = current_scene->get_entities();
    std::for_each(entities.begin(), entities.end(), [&](GameEntity* entity)
    {
        entity->move(glm::vec3(0.0f, 0.0f, 0.01f));
        entity->update();
    });
}

void SceneManager::add_to_render_queue()
{
    std::vector<GameEntity*> entities = current_scene->get_entities();
    std::for_each(entities.begin(), entities.end(), [&](GameEntity* entity)
    {
        entity->render();
    });
}

std::vector<Scene*>::iterator SceneManager::find_scene(Scene* scene)
{
    return std::find_if(scenes.begin(), scenes.end(), [&](Scene* _scene)
    {
        return scene == _scene;
    });
}

std::vector<Scene*>::iterator SceneManager::find_scene(const std::string& scene_name)
{
    return std::find_if(scenes.begin(), scenes.end(), [&](Scene* scene)
    {
        return scene_name == scene->get_name();
    });
}

void SceneManager::allocate_scene(const std::string& scene_name)
{
    scenes.push_back(new Scene(scene_name));
}

void SceneManager::deallocate_scene(Scene* scene)
{
    deallocate_scene(scene->get_name());
}

void SceneManager::deallocate_scene(const std::string& scene_name)
{
    auto itr = find_scene(scene_name);
    delete *itr;
    scenes.erase(itr);
}

bool SceneManager::change_scene(Scene* scene)
{
    return change_scene(scene->get_name());
}

bool SceneManager::change_scene(const std::string& scene_name)
{
    auto itr = find_scene(scene_name);

    if (itr != scenes.end())
    {
        current_scene = *itr;
    }
                      
    return itr != scenes.end();
}

glm::mat4 SceneManager::get_view() const
{
    return current_scene->get_view();
}

SceneManager::~SceneManager()
{
    std::for_each(scenes.begin(), scenes.end(), [&](Scene* scene)
    {
        delete scene;
        scene = nullptr;
    });
}