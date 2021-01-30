#include "engine.h"

void compute_fov(Entity player, GameMap map) {

	for (int x = 0; x < map.width; x++) {
		for (int y = 0; y < map.height; y++) {
			map.tiles[x][y].visible = player.sight_map.tiles[x][y].visible;
		}
	}
}