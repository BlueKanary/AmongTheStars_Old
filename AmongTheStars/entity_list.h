#pragma once

#include "entity.h"

struct EntityList { // Premade Enity list for easy entity creation

	// Lists will eventually be written in scripting format for easier modifications
	// from both Myself and Modders
	public:

		static const Entity player() { return(Entity(0, 0, 0, 10, 20, Color::white())); };

		static const Entity drifter_1(int x, int y) { return(Entity(x, y, 0, 10, 20, Color::dark_red())); };

};