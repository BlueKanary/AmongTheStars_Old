#include "proc_gen.h"

Rectangle::Rectangle(int x, int y, int width, int height) {

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

void gen_dungeon(int max_rooms, int min_room_size, int max_room_size, GameMap map, Entity& player) {

	std::vector<Rectangle> room_list;

	for (int i = 0; i < max_rooms; i++) {

		int width = std::rand() % (max_room_size - min_room_size) + min_room_size;
		int height = std::rand() % (max_room_size - min_room_size) + min_room_size;

		int x = std::rand() % (map.width - width);
		int y = std::rand() % (map.height - height);

		Rectangle new_room(x, y, width, height);

		bool intersect = false;			// checks if room is intersecting another
		for (auto room : room_list) {
			if (new_room.intersects(room)) {
				intersect = true;
			}
		}								// if room does intersect then try again
		if (intersect) {
			continue;		
		}

		clear_room(new_room, map);

		if (room_list.size() == 0) {
			player.x = new_room.x_center;
			player.y = new_room.y_center;
		}

		room_list.push_back(new_room);

	}

}

void fill_map(GameMap map) {		// Fills map with walls

	for (int x = 0; x < map.width; x++) {
		for (int y = 0; y < map.height; y++) {

			map.tiles[x][y] = TileType::wall();

		}
	}
}

void clear_room(Rectangle rect, GameMap map) {		// Turns inside of room with floor

	for (int x = rect.x1 + 1; x < rect.x2; x++) {
		for (int y = rect.y1 + 1; y < rect.y2; y++) {

			map.tiles[x][y] = TileType::floor();

		}
	}
}