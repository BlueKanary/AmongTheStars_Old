#pragma once

#include "game_map.h"
#include "tile_types.h"

#include "allegro5/allegro_color.h"

class Rectangle {

public:

	int x1;
	int y1;
	int x2;
	int y2;
	int x_center;
	int y_center;

	Rectangle(int x, int y, int width, int height);

};

void clear_area(Rectangle rect, GameMap map);