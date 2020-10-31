#pragma once

#include "allegro5/allegro_color.h"

struct Color {
	static const ALLEGRO_COLOR white() { return(al_map_rgba(255, 255, 255, 255)); }
	static const ALLEGRO_COLOR black() { return(al_map_rgba(0, 0, 0, 255)); }

	static const ALLEGRO_COLOR red() { return(al_map_rgba(255, 0, 0, 255)); }
	static const ALLEGRO_COLOR green() { return(al_map_rgba(0, 255, 0, 255)); }
	static const ALLEGRO_COLOR blue() { return(al_map_rgba(0, 0, 255, 255)); }

	static const ALLEGRO_COLOR yellow() { return(al_map_rgba(255, 255, 0, 255)); }
	static const ALLEGRO_COLOR cyan() { return(al_map_rgba(0, 255, 255, 255)); }
	static const ALLEGRO_COLOR magenta() { return(al_map_rgba(255, 0, 255, 255)); }
};