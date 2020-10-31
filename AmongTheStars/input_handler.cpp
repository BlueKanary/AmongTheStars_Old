#include "input_handler.h"

outcode input_handler(ALLEGRO_EVENT_QUEUE* event_queue) {

	outcode out;

	// Event Handler
	ALLEGRO_EVENT event;
	al_get_next_event(event_queue, &event);

	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		out.code = "exit";
	}

	// Keyboard
	ALLEGRO_KEYBOARD_STATE key_state;
	al_get_keyboard_state(&key_state);

	if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT)) {
		out.code = "move";
		out.x = 1;
		out.y = 0;
	}
	else if (al_key_down(&key_state, ALLEGRO_KEY_LEFT)) {
		out.code = "move";
		out.x = -1;
		out.y = 0;
	}
	else if (al_key_down(&key_state, ALLEGRO_KEY_DOWN)) {
		out.code = "move";
		out.x = 0;
		out.y = 1;
	}
	else if (al_key_down(&key_state, ALLEGRO_KEY_UP)) {
		out.code = "move";
		out.x = 0;
		out.y = -1;
	}

	if (event.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(event_queue)) {
		out.code = "timer";
	}

	return out;

}
