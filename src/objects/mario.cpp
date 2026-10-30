#include "mario.hpp"

#include "map_movable.hpp"

using sea::Mario;

Mario::Mario(const Coord& top_left, const int width, const int height) 
	: Movable(top_left, width, height, 0, 0) {}

sea::Rect Mario::get_rect() const noexcept {
	return {top_left, width, height};
}

sea::Speed Mario::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void Mario::move_map_left() noexcept {
	move_horizontal_offset(sea::MapMovable::MAP_STEP);
}

void Mario::move_map_right() noexcept {
	move_horizontal_offset(-sea::MapMovable::MAP_STEP);
}

void Mario::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void Mario::process_mario_collision(Collisionable* mario) noexcept {}

void Mario::process_vertical_static_collision(Rect* obj) noexcept {
	if (vspeed > 0) {
		// Марио упал на корабль.
		top_left.y -= vspeed;
	} else if (vspeed < 0) {
		// Марио ударился головой о полку и после этого должен падать вниз.
		top_left.y -= vspeed;
	}
	vspeed = 0;
}
