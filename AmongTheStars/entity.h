#pragma once

#include "fov.h"

#include "allegro5/allegro_color.h"

#include <string>

class Entity {

	public:

		std::string name;
		int x;
		int y;
		int char_x;
		int char_y;
		int sight_range;
		ALLEGRO_COLOR color;

		GameMap sight_map;
		MyVisibility fov;

		Entity(int dx, int dy, int char_dx, int char_dy, int range, ALLEGRO_COLOR dcolor, GameMap map);

		void move(int dx, int dy);
		void fov_compute();

};
