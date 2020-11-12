#include "entity.h"

Entity::Entity(int dx, int dy, int char_dx, int char_dy, ALLEGRO_COLOR dcolor) {
					// char x,y points to section in tileset
	x = dx;
	y = dy;
	char_x = char_dx;
	char_y = char_dy;
	color = dcolor;

}

void Entity::move(int dx, int dy) {
	x += dx;
	y += dy;
}

