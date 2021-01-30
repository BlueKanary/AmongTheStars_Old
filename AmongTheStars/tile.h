#pragma once

#include "color_list.h"

#include "allegro5/allegro_color.h"

#include <string>

class Tile {

	public:

		int char_x;						// x and y select sprite on tilemap
		int char_y;
		ALLEGRO_COLOR light;
		ALLEGRO_COLOR dark;
		bool walkable;				// walk on the tile
		bool transparent;			// see through the tile

		bool visible = false;		// you can see this tile
		bool explored = false;		// you have seen this tile

};

Tile type(int dx, int dy, ALLEGRO_COLOR light, ALLEGRO_COLOR dark, bool walkable, bool transparent);
// Used for premade tiles (wall, floor, etc)