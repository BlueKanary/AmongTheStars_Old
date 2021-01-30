#pragma once

#include "game_map.h"

// Adam Milazzo's Field of View Algorithm
// http://www.adammil.net/blog/v125_roguelike_vision_algorithms.html

struct LevelPoint {
	int x;
	int y;

	LevelPoint(int dx, int dy) { x = dx; y = dy; }
};

struct Slope {

	unsigned int x;
	unsigned int y;

	Slope(int dy, int dx) { x = dx; y = dy; }

	bool greater(int dy, int dx) { return y * dx > x * dy; }
	bool greater_or_equal(int dy, int dx) { return y * dx >= x * dy; }
	bool less(int dy, int dx) { return y * dx < x * dy; }

};

class MyVisibility {

	public:

		bool blocks_light(int x, int y, unsigned int z, LevelPoint origin, GameMap map);
		bool _blocks_light(int x, int y, GameMap map);

		void set_visible(int x, int y, unsigned int z, LevelPoint origin, GameMap map);
		void _set_visible(int x, int y, GameMap map);

		int get_distance(int x, int y);

		void fov_compute(LevelPoint origin, int range_limit, GameMap map);
		void compute(unsigned int octant, LevelPoint origin, int range_limit, unsigned int x, Slope top, Slope bottom, GameMap map);
};