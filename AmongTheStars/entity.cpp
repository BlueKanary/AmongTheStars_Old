#include "entity.h"

Entity::Entity(int dx, int dy, int char_dx, int char_dy, int range, ALLEGRO_COLOR dcolor) {
					
	x = dx;
	y = dy;
	char_x = char_dx;	// char x,y points to section in tileset
	char_y = char_dy;
	color = dcolor;

	sight_range = range;

}

void Entity::move(int dx, int dy) {
	x += dx;
	y += dy;
}

void Entity::fov_map(GameMap map) { // Update Sightmap

	// Separate from initializing entity to allow for updating map when tiles are created or destroyed

	sight_map = map;
}

void Entity::fov_compute() { // Update field of view
	LevelPoint origin(x, y);
	fov.fov_compute(origin, sight_range, sight_map);
}