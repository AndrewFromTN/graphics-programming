#include "Scene.hpp"
#include "Camera.hpp"
#include "TileMap.hpp"
#include "MapLoader.hpp"
#include "stb_image.h"
#include <algorithm>

Scene::Scene(const std::string& name)
{
    this->name = name;

    camera = new Camera(glm::vec3(0.0f, 0.0f, -1.7f));

    int width, height, nrChannels;
    unsigned char* entire_tilemap = stbi_load("./tile_sheet.png", &width, &height, &nrChannels, 0);

    MapLoader loader;
    int tile_count = 0;
    float* tiles = loader.loadMapFile("./map.tmx", tile_count);

    GameEntity* tilemap = new TileMap("tile_shader", tiles, tile_count, tile_count, width, height, nrChannels, entire_tilemap);
    //entities.push_back(tilemap);

    unsigned char* red = stbi_load("./red.png", &width, &height, &nrChannels, 0);

    float stuff[20] = {
        0.0f, 0.25f, 0.0f,  0.0f, 1.0f,
        0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
        0.25f, 0.25f, 0.0f, 1.0f, 1.0f,
        0.25f, 0.0f, 0.0f,  1.0f, 0.0f
    };

    GameEntity* test = new GameEntity("tile_shader", stuff, 20, width, height, nrChannels, red);
    entities.push_back(test);

    stbi_image_free(entire_tilemap);
    stbi_image_free(red);
}

std::string Scene::get_name() const
{
    return name;
}

glm::mat4 Scene::get_view() const
{
    return camera->get_view();
}

std::vector<GameEntity*> Scene::get_entities() const
{
    return entities;
}

Scene::~Scene()
{
    delete camera;
    camera = nullptr;

    std::for_each(entities.begin(), entities.end(), [&](GameEntity* entity)
    {
        delete entity;
        entity = nullptr;
    });
}