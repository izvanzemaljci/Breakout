#pragma once

#ifndef BRICKMAP_H
#define BRICKMAP_H

#define SDL_MAIN_HANDLED
#include <string>

class BrickMap {
	public:
		BrickMap();
		~BrickMap();

		static void loadBrickMap(std::string path, int sizeX, int sizeY, int colSpace, int rowSpace);
		static void AddTile(int x, int y, int w, int h, int id);
		static void DeleteTile();
};

#endif
