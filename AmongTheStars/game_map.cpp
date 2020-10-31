#include "game_map.h"

GameMap::GameMap(int dwidth, int dheight) {

	width = dwidth;
	height = dheight;

	tiles = new Tile*[width];

	for (int i = 0; i < width; i++) {

		tiles[i] = new Tile[height];

	}

}

bool GameMap::is_blocked(int x,int y) {

	bool boolean = false;

	if (tiles[x][y].blocked) {
		boolean = true;
	}

	return boolean;
}