#pragma once

#include "tile.h"

#include <vector>

class GameMap {

	public:

		int width;
		int height;
		Tile** tiles;

		GameMap(int width, int height);
		bool is_blocked(int x, int y);
};