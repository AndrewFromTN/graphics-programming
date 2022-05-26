#include "MapLoader.hpp"

#include <cmath>
#include "rapidxml.hpp"
#include "GlobalDefines.hpp"
#include <glm/glm.hpp>

MapLoader::MapLoader() 
{
	width = 512; height = 512; //Default values, these get changed.	
	tileCount = width * height;
}

float* MapLoader::loadMapFile(const char* filePath, int& tile_count)
{
	rapidxml::xml_document<> doc;

	std::ifstream file(filePath);

	std::stringstream buffer;

	buffer << file.rdbuf();

	file.close();

	std::string content(buffer.str());

	doc.parse<0>(&content[0]);

	std::vector<int> gids;
	float x = 0;
	float y = 0;

	rapidxml::xml_node<>* pRoot = doc.first_node();

	//Get the tileset file
	rapidxml::xml_node<>* tilesetNode = pRoot->first_node("tileset");
	tilesetTextureFilePath = tilesetNode->first_node("image")->first_attribute("source")->value();

	//rapidxml::xml_attribute<>* tileCountAttribute = tilesetNode->first_attribute("tilecount");

	//Get width and height
	rapidxml::xml_node<>* layer1Node = pRoot->first_node("layer");
	rapidxml::xml_attribute<>* widthAttribute = layer1Node->first_attribute("width");
	rapidxml::xml_attribute<>* heightAttribute = layer1Node->first_attribute("height");

	int width = atoi(widthAttribute->value());
	int height = atoi(heightAttribute->value());

	tile_count = width * height;

	map = new float[tile_count * 20];

	int i = 0;

	const float TILE_WIDTH = 32.f;
	const float TILE_HEIGHT = 32.f;

	const float SHEET_WIDTH = 512.f;
	const float SHEET_HEIGHT = 512.f;

	for(rapidxml::xml_node<>* layer_node = pRoot->first_node("layer"); layer_node; layer_node = layer_node->next_sibling())
	{
		rapidxml::xml_node<>* data_node = layer_node->first_node("data");

		for(rapidxml::xml_node<>* tile_node = data_node->first_node("tile"); tile_node; tile_node = tile_node->next_sibling()) 
		{
			int gid = atoi(tile_node->first_attribute("gid")->value());

			int gid_x = 16;
			int gid_y = 16;

			int j = gid % gid_x;

			if (j == 0)
			{
				j = width;
			}

			int k = std::floor(gid / gid_y);

			map[i] = x * TILE_WIDTH;
			map[i + 1] = (y + 1) * TILE_HEIGHT;
			map[i + 2] = 0;
			map[i + 3] = ((j - 1) * TILE_WIDTH) / SHEET_WIDTH;
			map[i + 4] = ((k + 1) * TILE_HEIGHT) / SHEET_HEIGHT;

			map[i + 5] = x * TILE_WIDTH;
			map[i + 6] = y * TILE_HEIGHT;
			map[i + 7] = 0;
			map[i + 8] = ((j - 1) * TILE_WIDTH) / SHEET_WIDTH;
			map[i + 9] = (k * TILE_HEIGHT) / SHEET_HEIGHT;

			map[i + 10] = (x + 1) * TILE_WIDTH;
			map[i + 11] = (y + 1) * TILE_HEIGHT;
			map[i + 12] = 0;
			map[i + 13] = (j * TILE_WIDTH) / SHEET_WIDTH;
			map[i + 14] = ((k + 1) * TILE_HEIGHT) / SHEET_HEIGHT;

			map[i + 15] = (x + 1) * TILE_WIDTH;
			map[i + 16] = y * TILE_HEIGHT;
			map[i + 17] = 0;
			map[i + 18] = (j * TILE_WIDTH) / SHEET_WIDTH;
			map[i + 19] = (k * TILE_HEIGHT) / SHEET_HEIGHT;

			if(x >= width - 1)
			{
				++y;

				x = 0;
			}
			else
			{
				++x;
			}

			i += 20;
		}
		break;
	}

	this->width = width;
	this->height = height;

	return map;
}

MapLoader::~MapLoader()
{

}


