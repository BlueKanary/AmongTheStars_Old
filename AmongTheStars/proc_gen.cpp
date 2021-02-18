#include "proc_gen.h"

; Rectangle::Rectangle(int x, int y, int dwidth, int dheight) { // Class for rectangular rooms

	width = dwidth;
	height = dheight;

	x1 = x;
	y1 = y;
	x2 = x + width;
	y2 = y + height;

	x_center = (x1 + x2) / 2;
	y_center = (y1 + y2) / 2;

}

bool Rectangle::intersects(Rectangle rect) {	// Check for intersection with other room

	bool intersect = false; 

	if (x1 <= rect.x2 && y1 <= rect.y2 && x2 >= rect.x1 && y2 >= rect.y1) {
		intersect = true;
	}

	return intersect;

}

GameMap gen_dungeon(int max_rooms, int min_room_size, int max_room_size, int floor_width, int floor_height, Entity& player,
	Entity entities[], int e_list_num) {

	std::vector<Rectangle> room_list;

	// create temp map
	GameMap new_floor(floor_width, floor_height);

	fill_map(new_floor);

	for (int i = 0; i < max_rooms; i++) {	// Generates map using basic algorithm

		int width = std::rand() % (max_room_size - min_room_size) + min_room_size;
		int height = std::rand() % (max_room_size - min_room_size) + min_room_size;

		int x = std::rand() % (new_floor.width - width);
		int y = std::rand() % (new_floor.height - height);

		Rectangle new_room(x, y, width, height);

		bool intersect = false;			// checks if room is intersecting another
		for (Rectangle room : room_list) {
			if (new_room.intersects(room)) {
				intersect = true;
			}
		}								// if room does intersect then try again
		if (intersect) {
			continue;
		}
		
		clear_room(new_room, new_floor);

		int entity_amount = 1;
		for (int i = 0; i < entity_amount; i++) {	// Place entities in room
			int x = std::rand() % (new_room.width - 1) + (new_room.x1 + 1);
			int y = std::rand() % (new_room.height - 1) + (new_room.y1 + 1);

			if (e_list_num >= 256) { break; }

			intersect = false;
			for (int n = 0; n < e_list_num; n++) {
				if (x == entities[n].x && y == entities[n].y) {
					intersect = true;
				}
			}								// if entity is on top of another dont spawn
			if (intersect) {
				continue;
			}

			Entity entity = EntityList::drifter_1(x, y);
			entities[e_list_num] = entity;
			e_list_num++;
		}
		
		if (room_list.size() == 0) {			// put player in center of first room
			player.x = new_room.x_center;
			player.y = new_room.y_center;
		} else {								// gets a hall from center of new_room to center of old room
			
			Rectangle old_room = room_list.at(room_list.size() - 1);
			clear_hall(new_room.x_center, new_room.y_center, old_room.x_center, old_room.y_center, new_floor);

		}

		room_list.push_back(new_room);

	}

	return new_floor;

}

void fill_map(GameMap new_floor) {		// Fills map with walls

	for (int x = 0; x < new_floor.width; x++) {
		for (int y = 0; y < new_floor.height; y++) {

			new_floor.tiles[x][y] = TileType::wall();

		}
	}
}

void clear_room(Rectangle rect, GameMap new_floor) {		// Turns inside of room with floor

	for (int x = rect.x1 + 1; x < rect.x2; x++) {
		for (int y = rect.y1 + 1; y < rect.y2; y++) {

			new_floor.tiles[x][y] = TileType::floor();

		}
	}
}

void clear_hall(int x1, int y1, int x2, int y2, GameMap new_floor) {

	int corner_x;
	int corner_y;

	if (rand() % 10 < 5) {		// horizontal first
		corner_x = x2;
		corner_y = y1;
	} else {					// vertical first
		corner_x = x1;
		corner_y = y2;
	}

	int x_dir;
	int y_dir;

	if (x1 < x2) {		// checking if room two is more or less than room one x
		x_dir = 1;
	} else {
		x_dir = -1;
	}
	if (y1 < y2) {		// checking if room two is more or less than room one y
		y_dir = 1;
	}
	else {
		y_dir = -1;
	}

	for (int x = x1; x != x2; x += x_dir) {
		new_floor.tiles[x][corner_y] = TileType::floor();
	}
	for (int y = y1; y != y2; y += y_dir) {
		new_floor.tiles[corner_x][y] = TileType::floor();
	}

}
