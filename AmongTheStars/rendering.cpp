#include "rendering.h"

void render_all(ALLEGRO_BITMAP* bitmap, Entity entities[], GameMap map, Camera camera) {

	al_clear_to_color(Color::black());

	for (int x = 0; x < map.width; x++) {

		for (int y = 0; y < map.height; y++) {

			ALLEGRO_COLOR color = Color::black();

			if (map.tiles[x][y].visible) {
				color = map.tiles[x][y].light;
			} else if (map.tiles[x][y].explored) {
				color = map.tiles[x][y].dark;
			}

			draw_tile(bitmap, map, camera, x, y, color);

		}
	}

	for (int i = 0; i < 256; i++) {
		Entity entity = entities[i];

		if (!entity.blank) {
			draw_entity(bitmap, entity, camera);
		}

		
	}

	al_flip_display();
}

void draw_tile(ALLEGRO_BITMAP* bitmap, GameMap map, Camera camera, int x, int y, ALLEGRO_COLOR color) {
	al_draw_tinted_bitmap_region(bitmap, color, map.tiles[x][y].char_x, map.tiles[x][y].char_y, 10, 10,
		(x + camera.x_position()) * 10, (y + camera.y_position()) * 10, 0);
}

void draw_entity(ALLEGRO_BITMAP* bitmap, Entity entity, Camera camera) {
	al_draw_tinted_bitmap_region(bitmap, entity.color, entity.char_x, entity.char_y, 10, 10, 
		(entity.x + camera.x_position()) * 10, (entity.y + camera.y_position()) * 10, 0);
}										// Tileset select = select x, select y, size x, size y
