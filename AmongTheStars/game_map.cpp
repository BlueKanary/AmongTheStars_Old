#include "game_map.h"
#include <iostream>

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

	if (tiles[x][y].walkable) {
		boolean = true;
	}

	return boolean;
}

bool GameMap::in_bounds(int x, int y, GameMap game_map) {

	bool boolean = false;
	std::cout << x << " " << y << std::endl;

	// 0 is less than [position] is less than map width and map height
	if (0 <= x && x < game_map.width && 0 <= y && y < game_map.height) {
		boolean = true;
	}

	/*	
		Leaving x array will crash game which makes sense
		Leaving the y array will not. It will set itself to max or min of the array (ex. 0 and 60)
		May be caused by for loop declaration of array. Irrelevent currently, keep eye on it
	*/	

	std::cout << boolean << std::endl;

	return boolean;

}