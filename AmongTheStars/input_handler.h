#pragma once

#include "allegro5/allegro.h"

#include <string>

struct outcode {

	std::string code = "";
	int x = 0;
	int y = 0;
	int z = 0;

};

outcode input_handler(ALLEGRO_EVENT_QUEUE* event_queue);