#include "BrickMap.h"
#include "game.h"
#include <fstream>
#include "System\System.h"
#include "System\Components.h"

extern Manager manager; 

BrickMap::BrickMap()
{

}

BrickMap::~BrickMap()
{

}

void BrickMap::loadBrickMap(std::string path, int sizeX, int sizeY, int colSpace, int rowSpace)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			BrickMap::AddTile(x * 10 * rowSpace + 103, y * 4 * colSpace + 134, 24, 8, ((int)tile));
			mapFile.ignore();
		}
	}

	mapFile.close();
}

void BrickMap::AddTile(int x, int y, int w, int h, int id)
{
	auto &tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, w, h, id);
	tile.addGroup(Game::groupMap);
}