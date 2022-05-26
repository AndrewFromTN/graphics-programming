#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

class MapLoader
{
	private:
		//void createQuad(sf::VertexArray &va, int x, int y, const sf::Vector2u &tileSize, int tilesetTextureX, const std::vector<int> &layergIDs, int i);
		//void loadMapTilesheet(std::string tileset, const sf::Vector2u &tileSize, unsigned int width, unsigned int height);

		int width, height;
		
		float* map;

		std::string tilesetTextureFilePath;
	public:
		MapLoader();
		~MapLoader();

		float* loadMapFile(const char* filePath, int& tile_count);

		int tileCount;
};

#endif