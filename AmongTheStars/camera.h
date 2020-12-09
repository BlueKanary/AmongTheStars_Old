#pragma once

#include "game_map.h"
#include "entity.h"

class Camera {

	public:
		int width;
		int height;

		int center_x;
		int center_y;
	
		Camera(Entity player, int dwidth, int dheight);

		void reposition(Entity player);

		int x_position() { return width / 2 - center_x; }
		int y_position() { return height / 2 - center_y; }

};