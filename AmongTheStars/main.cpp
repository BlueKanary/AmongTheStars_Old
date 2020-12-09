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
	bitmap = al_load_bitmap("arial10x10.png");
	sample = al_load_sample("bensound-scifi.mp3");

	// Audio Sample
	sample_instance = al_create_sample_instance(sample);
	al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());

	// Event Sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(fps_timer));

	// Error when not loaded
	assert(bitmap != NULL);
	assert(sample != NULL);

	// Set Seed
	std::srand(time(NULL));

	// Game Variables
	GameMap game_map(100, 60);
	fill_map(game_map);

	std::vector<Entity> entities;

	Entity e(10, 10, 0, 10, 25, al_map_rgba(255, 255, 255, 255), game_map);
	entities.push_back(e); // Copy "e" into entity list

	Entity& player = entities.at(0); // get pointer for player

	gen_dungeon(100, 10, 20, game_map, player);

	player.fov_compute();
	compute_fov(player, game_map);

	Camera camera(player, 108, 72);

	// Game Loop
	bool running = true;
	al_start_timer(fps_timer);
	while (running) {

		outcode out = input_handler(event_queue);

		if (out.code == "exit") { // close game
			running = false;
		}
		if (out.code == "move") {

			if (game_map.in_bounds(player.x + out.x, player.y + out.y, game_map)) { // check in bounds of the map
				if (game_map.is_blocked(player.x + out.x, player.y + out.y)) {		// check inside map for walls
					player.move(out.x, out.y);
					player.fov_compute();
					compute_fov(player, game_map);
					camera.reposition(player);
				}
			}
		}
		if (out.code == "timer") {
			render_all(bitmap, entities, game_map, camera);
		}

		//if (!al_get_sample_instance_playing(sample_instance)) {
		//	al_play_sample_instance(sample_instance);
		//}		Music loop - In Progress
	}
	
	al_uninstall_system();
	return 0;

}