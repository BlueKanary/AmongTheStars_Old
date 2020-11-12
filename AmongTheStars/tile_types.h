#pragma once

#include "tile.h"

struct TileType {

	static const Tile wall() { return(type(130, 10, Color::dark_yellow(), Color::dark_blue(), false, false)); }
	static const Tile floor() { return(type(130, 10, Color::yellow(), Color::blue(), true, true)); }

};