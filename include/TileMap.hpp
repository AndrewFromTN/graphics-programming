#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include "GameEntity.hpp"

// ToDo(andrew): We need an EBO (and VBO) for our tile map
// so we don't draw extra vertices and we can batch the map draw


class TileMap : public GameEntity
{
    private:

    public:
        TileMap(const std::string& shader, float* vertices, int num_rects, int num_components, 
                unsigned int texture_width, unsigned int texture_height, unsigned int texture_channels,
                unsigned char* texture_data);
        ~TileMap();
};

#endif