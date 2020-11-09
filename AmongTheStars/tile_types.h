#pragma once

#include "tile.h"

struct TileType {

	static const Tile wall() { return(type(130, 10, Color::red(), Color::dark_red(), false, false)); }
	static const Tile floor() { return(type(110, 10, Color::blue(), Color::dark_blue(), true, true)); }

};