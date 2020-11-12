#include "proc_gen.h"

Rectangle::Rectangle(int x, int y, int width, int height) {

	x1 = x;
	y1 = y;
	x2 = x + width;
	y2 = y + height;

	x_center = (x1 + x2) / 2;
	y_center = (y1 + y2) / 2;

}

bool Rectangle::intersects(Rectangle rect) {	// Check for intersection with other room

	bool intersect = false; 

	if (x1 <= rect.x2 && y1 <= rect.y2 && x2 >= rect.x1 && y2 >= rect.y1) {
		intersect = true;
	}

	return intersect;

}

void gen_dungeon() {



}

void fill_map(GameMap map) {		// Fills map with walls

	for (int x = 0; x < map.width; x++) {
		for (int y = 0; y < map.height; y++) {

			map.tiles[x][y] = TileType::wall();

		}
	}
}

void clear_room(Rectangle rect, GameMap map) {		// Turns inside of room with floor

	for (int x = rect.x1 + 1; x < rect.x2; x++) {
		for (int y = rect.y1 + 1; y < rect.y2; y++) {

			map.tiles[x][y] = TileType::floor();

		}
	}
}