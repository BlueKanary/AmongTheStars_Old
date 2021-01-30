#include "tile.h"

Tile type(int dx, int dy, ALLEGRO_COLOR light, ALLEGRO_COLOR dark, bool walkable, bool transparent) {

	Tile tile;

	tile.char_x = dx;
	tile.char_y = dy;
	tile.light = light;
	tile.dark = dark;
	tile.walkable = walkable;
	tile.transparent = transparent;

	return tile;
}