#include "fov.h"

bool MyVisibility::blocks_light(int x, int y, unsigned int octant, LevelPoint origin, GameMap map) {
	unsigned int nx = origin.x, ny = origin.y;
	switch (octant)
	{
	case 0: nx += x; ny -= y; break;
	case 1: nx += y; ny -= x; break;
	case 2: nx -= y; ny -= x; break;
	case 3: nx -= x; ny -= y; break;
	case 4: nx -= x; ny += y; break;
	case 5: nx -= y; ny += x; break;
	case 6: nx += y; ny += x; break;
	case 7: nx += x; ny += y; break;
	}
	return _blocks_light((int)nx, (int)ny, map);
}

bool MyVisibility::_blocks_light(int x, int y, GameMap map) {
	if (x < map.width && y < map.height && x >= 0 && y >= 0) return !map.tiles[x][y].transparent;
}

void MyVisibility::set_visible(int x, int y, unsigned int octant, LevelPoint origin, GameMap map) {
	unsigned int nx = origin.x, ny = origin.y;
	switch (octant)
	{
	case 0: nx += x; ny -= y; break;
	case 1: nx += y; ny -= x; break;
	case 2: nx -= y; ny -= x; break;
	case 3: nx -= x; ny -= y; break;
	case 4: nx -= x; ny += y; break;
	case 5: nx -= y; ny += x; break;
	case 6: nx += y; ny += x; break;
	case 7: nx += x; ny += y; break;
	}
	_set_visible((int)nx, (int)ny, map);
}

void MyVisibility::_set_visible(int x, int y, GameMap map) {
	if (x < map.width && y < map.height && x >= 0 && y >= 0) {
		map.tiles[x][y].visible = true;
		map.tiles[x][y].explored = true;
	}
}

int MyVisibility::get_distance(int x, int y) {
	return sqrt(x ^ 2 + y ^ 2);
}

void MyVisibility::fov_compute(LevelPoint origin, int range_limit, GameMap map) {

	for (int x = 0; x < map.width; x++) {
		for (int y = 0; y < map.height; y++) {
			map.tiles[x][y].visible = false;
		}
	}

	_set_visible(origin.x, origin.y, map);

	Slope top(1, 1); Slope bottom(0, 1);

	for (unsigned int octant = 0; octant < 8; octant++) {
		compute(octant, origin, range_limit, 1, top, bottom, map);
	}

}

void MyVisibility::compute(unsigned int octant, LevelPoint origin, int range_limit, unsigned int x, Slope top, Slope bottom, GameMap map) {

	for (; x <= (unsigned int)range_limit; x++) {

		unsigned int top_y;
		if (top.x == 1) {
			top_y = x;
		} else {
			top_y = ((x * 2 - 1) * top.y + top.x) / (top.x * 2);
			if (blocks_light(x, top.y, octant, origin, map)) {
				if (top.greater_or_equal(top_y * 2 + 1, x * 2) && !blocks_light(x, top_y + 1, octant, origin, map)) top_y++;
			} else {
				unsigned int ax = x * 2;
				if (blocks_light(x + 1, top_y + 1, octant, origin, map)) ax++;
				if (top.greater(top_y * 2 + 1, ax)) top_y++;
			}
		}

		unsigned int bottom_y;
		if (bottom.y == 0) {
			bottom_y = 0;
		} else {
			bottom_y = ((x * 2 - 1) * bottom.y + bottom.x) / ((bottom.x * 2));
			if (bottom.greater_or_equal(bottom_y * 2 + 1, x * 2) && blocks_light(x, bottom_y, octant, origin, map) &&
				!blocks_light(x, bottom_y + 1, octant, origin, map)) bottom_y++;
		}

		int was_opaque = -1;
		for (unsigned int y = top_y; (int)y >= (int)bottom_y; y--) {
			if (range_limit < 0 || get_distance((int)x, (int)y) <= range_limit) {
				bool is_opaque = blocks_light(x, y, octant, origin, map);
				bool is_visible =
				is_opaque || ((y != top_y || top.greater(y * 4 - 1, x * 4 + 1)) && (y != bottom_y || bottom.less(y * 4 + 1, x * 4 - 1)));
				if (is_visible) set_visible(x, y, octant, origin, map);
				if (x != range_limit) {
					if (is_opaque) {
						if (was_opaque == 0) {
							unsigned int nx = x * 2, ny = y * 2 + 1;
							if (blocks_light(x, y + 1, octant, origin, map)) nx--;
							if (top.greater(ny, nx)) {
								if (y == bottom_y) {
									bottom = Slope(ny, nx); 
									break;
								} else {
									compute(octant, origin, range_limit, x + 1, top, Slope(ny, nx), map);
								}
							} else {
								if (y == bottom_y) return;
							}
						}
						was_opaque = 1;
					} else {
						if (was_opaque > 0) {
							unsigned int nx = x * 2, ny = y * 2 + 1;
							if (blocks_light(x + 1, y + 1, octant, origin, map)) nx++;
							if (bottom.greater_or_equal(ny, nx)) return;
							top = Slope(ny, nx);
						}
						was_opaque = 0;
					}
				}
			}
		}
		if (was_opaque != 0) break;
	}
}