#pragma once

#include "entity.h"
#include "game_map.h"
#include "color_list.h"

#include "allegro5/allegro_image.h"
#include "allegro5/allegro_color.h"

#include <vector>

void render_all(ALLEGRO_BITMAP* bitmap, std::vector<Entity> entities, GameMap map);
void draw_tile(ALLEGRO_BITMAP* bitmap, GameMap map, int x, int y, ALLEGRO_COLOR color);
void draw_entity(ALLEGRO_BITMAP* bitmap, Entity entity);