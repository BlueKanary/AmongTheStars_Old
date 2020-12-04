#pragma once

#include "game_map.h"
#include "entity.h"
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

void gen_dungeon(int max_rooms, int min_room_size, int max_room_size, GameMap map, Entity& player);

void fill_map(GameMap map);
void clear_room(Rectangle rect, GameMap map);
void clear_hall(int x1, int y1, int x2, int y2, GameMap map);