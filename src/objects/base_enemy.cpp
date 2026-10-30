#include "base_enemy.hpp"

using sea::BaseEnemy;

BaseEnemy::BaseEnemy(const Coord& top_left, const int width, const int height)
	: RectMapMovableAdapter(top_left, width, height) {}

sea::Rect BaseEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

sea::Speed BaseEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void BaseEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}
