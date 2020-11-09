#pragma once

#include "allegro5/allegro_color.h"

#include <string>

class Entity {

	public:

		std::string name;
		int x;
		int y;
		int char_x;
		ALLEGRO_COLOR light;

		Entity(int dx, int dy, int char_dx, int char_dy, ALLEGRO_COLOR dcolor);

		void move(int dx, int dy);

};
