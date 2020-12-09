#include "camera.h"

Camera::Camera(Entity player, int dwidth, int dheight) {

	center_x = player.x;
	center_y = player.y;

	width = dwidth;
	height = dheight;

}

void Camera::reposition(Entity player) {

	center_x = player.x;
	center_y = player.y;

}