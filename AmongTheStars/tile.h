#pragma once

#include "color_list.h"

#include "allegro5/allegro_color.h"

#include <string>

class Tile {

	public:

		int char_x = 130;
		int char_y = 10;
		ALLEGRO_COLOR color = Color::blue();
		bool blocked = true;
		bool sight_blocked = false;

		bool visible = false;
		bool explored = false;


};
