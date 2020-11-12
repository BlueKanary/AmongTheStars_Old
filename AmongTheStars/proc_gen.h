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

	bool intersects(Rectangle rect);
};

void fill_map(GameMap map);
void clear_room(Rectangle rect, GameMap map);