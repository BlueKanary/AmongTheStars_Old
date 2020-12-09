#include "entity.h"

Entity::Entity(int dx, int dy, int char_dx, int char_dy, int range, ALLEGRO_COLOR dcolor, GameMap map) {
					// char x,y points to section in tileset
	x = dx;
	y = dy;
	char_x = char_dx;
	char_y = char_dy;
	color = dcolor;

	sight_range = range;
	sight_map = map;

}

void Entity::move(int dx, int dy) {
	x += dx;
	y += dy;
}

void Entity::fov_compute() {
	LevelPoint origin(x, y);
	fov.fov_compute(origin, sight_range, sight_map);
}