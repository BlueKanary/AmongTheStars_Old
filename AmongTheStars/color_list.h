#pragma once

#include "allegro5/allegro_color.h"

struct Color {	// Premade Colors
	static const ALLEGRO_COLOR white() { return(al_map_rgba(255, 255, 255, 255)); }
	static const ALLEGRO_COLOR grey() { return(al_map_rgba(125, 125, 125, 255)); }
	static const ALLEGRO_COLOR black() { return(al_map_rgba(0, 0, 0, 255)); }

	static const ALLEGRO_COLOR light_red() { return(al_map_rgba(255, 125, 125, 255)); }
	static const ALLEGRO_COLOR red() { return(al_map_rgba(255, 0, 0, 255)); }
	static const ALLEGRO_COLOR dark_red() { return(al_map_rgba(125, 0, 0, 255)); }

	static const ALLEGRO_COLOR light_green() { return(al_map_rgba(125, 255, 125, 255)); }
	static const ALLEGRO_COLOR green() { return(al_map_rgba(0, 255, 0, 255)); }
	static const ALLEGRO_COLOR dark_green() { return(al_map_rgba(0, 125, 0, 255)); }

	static const ALLEGRO_COLOR light_blue() { return(al_map_rgba(125, 125, 255, 255)); }
	static const ALLEGRO_COLOR blue() { return(al_map_rgba(0, 0, 255, 255)); }
	static const ALLEGRO_COLOR dark_blue() { return(al_map_rgba(0, 0, 125, 255)); }

	static const ALLEGRO_COLOR light_yellow() { return(al_map_rgba(255, 255, 125, 255)); }
	static const ALLEGRO_COLOR yellow() { return(al_map_rgba(255, 255, 0, 255)); }
	static const ALLEGRO_COLOR dark_yellow() { return(al_map_rgba(125, 125, 0, 255)); }

	static const ALLEGRO_COLOR cyan() { return(al_map_rgba(0, 255, 255, 255)); }
	static const ALLEGRO_COLOR magenta() { return(al_map_rgba(255, 0, 255, 255)); }

	static const ALLEGRO_COLOR orange() { return(al_map_rgba(255, 125, 0, 255)); }
	static const ALLEGRO_COLOR turquoise() { return(al_map_rgba(0, 255, 125, 255)); }
	static const ALLEGRO_COLOR violet() { return(al_map_rgba(125, 0, 255, 255)); }

	static const ALLEGRO_COLOR pink() { return(al_map_rgba(255, 0, 125, 255)); }
	static const ALLEGRO_COLOR azure() { return(al_map_rgba(0, 125, 255, 255)); }
	static const ALLEGRO_COLOR lime() { return(al_map_rgba(125, 255, 0, 255)); }


};