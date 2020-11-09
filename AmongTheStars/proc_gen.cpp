#include "proc_gen.h"

Rectangle::Rectangle(int x, int y, int width, int height) {

	x1 = x;
	y1 = y;
	x2 = x + width;
	y2 = y + height;

	x_center = (x1 + x2) / 2;
	y_center = (y1 + y2) / 2;

}

void clear_area(Rectangle rect, GameMap map) {

	for (int x = rect.x1; x < rect.x2; x++) {
		for (int y = rect.y1; y < rect.y2; y++) {

			map.tiles[x][y] = TileType::floor();

		}
	}
}