// Among the Stars - v0.1

#include "main.h"

int main(int argc, char** argv) {

	// Allegro Initilization
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* fps_timer;
	ALLEGRO_BITMAP* bitmap = NULL;
	ALLEGRO_SAMPLE* sample = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sample_instance = NULL;

	al_init();
	al_init_image_addon();
	al_init_acodec_addon();

	al_install_audio();
	al_install_keyboard();
	al_install_mouse();

	al_reserve_samples(1);
	
	// Create allegro stuff
	display = al_create_display(1080, 640);
	event_queue = al_create_event_queue();
	fps_timer = al_create_timer(1.0 / 100);

	//bitmap = al_load_bitmap("arial10x10.png");
	//sample = al_load_sample("bensound-scifi.mp3");

	// Audio Sample
	sample_instance = al_create_sample_instance(sample);
	al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());

	// Event Sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(fps_timer));

	// Error when not loaded
	//assert(bitmap != NULL);
	//assert(sample != NULL);

	// Set Seed
	std::srand(time(NULL));

	// Game Variables
	
	// Game Loop
	bool running = true;
	al_start_timer(fps_timer);
	while (running) {

		outcode out = input_handler(event_queue);

		handle_actions(out);

		//if (!al_get_sample_instance_playing(sample_instance)) {
		//	al_play_sample_instance(sample_instance);
		//}		Music loop - In Progress
	}
	
	al_uninstall_system();
	return 0;

}