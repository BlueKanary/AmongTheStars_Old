#pragma once

#include "entity.h"
#include "game_map.h"
#include "input_handler.h"

void compute_fov(Entity player, GameMap map);
void handle_actions(outcode out);