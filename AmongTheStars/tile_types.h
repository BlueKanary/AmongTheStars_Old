#pragma once

#include "tile.h"

struct TileType { // Premade Tile list. Useful for multiple wall types with different sprites

	// Lists will eventually be written in scripting format for easier modifications
	// from both Myself and Modders

	static const Tile wall() { return(type(130, 10, Color::dark_yellow(), Color::dark_blue(), false, false)); }
	static const Tile floor() { return(type(130, 10, Color::yellow(), Color::blue(), true, true)); }

};