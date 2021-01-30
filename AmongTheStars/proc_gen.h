#pragma once

#include "game_map.h"
#include "entity.h"
#include "tile_types.h"
#include "entity_list.h"

#include "allegro5/allegro_color.h"

#include <vector>
#include <iostream>

class Rectangle {

public:

	int width;
	int height;

	int x1;
	int y1;
	int x2;
	int y2;

	int x_center;
	int y_center;

	Rectangle(int x, int y, int width, int height);

	bool intersects(Rectangle rect);
};

GameMap gen_dungeon(int max_rooms, int min_room_size, int max_room_size, int floor_width, int floor_height, Entity& player);
//std::vector<Entity> place_entities(GameMap map);

void fill_map(GameMap new_floor);
void clear_room(Rectangle rect, GameMap new_floor);
void clear_hall(int x1, int y1, int x2, int y2, GameMap new_floor);
