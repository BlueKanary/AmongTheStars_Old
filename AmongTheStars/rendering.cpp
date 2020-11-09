#include "rendering.h"

void render_all(ALLEGRO_BITMAP* bitmap, std::vector<Entity> entities, GameMap map) {

	al_clear_to_color(Color::black());

	for (int x = 0; x < map.width; x++) {

		for (int y = 0; y < map.height; y++) {

			draw_tile(bitmap, map, x, y);

		}
	}
	for (int i = 0; i < entities.size(); i++) {

		Entity entity = entities.at(i);
		draw_entity(bitmap, entity);
	}

	al_flip_display();
}

void draw_tile(ALLEGRO_BITMAP* bitmap, GameMap map, int x, int y) {
	al_draw_tinted_bitmap_region(bitmap, map.tiles[x][y].light, map.tiles[x][y].x, map.tiles[x][y].y, 10, 10, x * 10, y * 10, 0);
}

void draw_entity(ALLEGRO_BITMAP* bitmap, Entity entity) {
	al_draw_tinted_bitmap_region(bitmap, entity.light, entity.char_x, entity.y, 10, 10, entity.x * 10, entity.y * 10, 0);
}										// Tileset select = select x, select y, size x, size y
