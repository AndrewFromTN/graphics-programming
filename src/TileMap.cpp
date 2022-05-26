#include "TileMap.hpp"

TileMap::TileMap(const std::string& shader, float* vertices, int num_rects, int num_components, 
                 unsigned int texture_width, unsigned int texture_height, unsigned int texture_channels,
                 unsigned char* texture_data) 
                : GameEntity()
{
    size_t size = num_rects;

    unsigned int* indices = new unsigned int[size * 6];

    for (size_t i = 0; i < size; ++i)
    {
        int index = i * 4;
        int offset = i * 6;

        indices[offset] = index;
        indices[offset + 1] = index + 1;
        indices[offset + 2] = index + 2;

        indices[offset + 3] = index + 1;
        indices[offset + 4] = index + 2;
        indices[offset + 5] = index + 3;
    }

    initialize_graphics(vertices, num_rects, indices, 20, shader, texture_width, texture_height, texture_channels, texture_data);
}

TileMap::~TileMap()
{
    
}