#include "flying_enemy.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

using sea::FlyingEnemy;

FlyingEnemy::FlyingEnemy(
	const Coord& top_left, const int width, const int height,
	const float patrol_distance, const float speed
) : BaseEnemy(top_left, width, height), patrol_distance(patrol_distance) {
	if (!std::isfinite(patrol_distance) || patrol_distance <= 0
		|| !std::isfinite(speed) || speed <= 0) {
		throw std::invalid_argument("FlyingEnemy requires positive finite distance and speed");
	}
	hspeed = speed;
}

void FlyingEnemy::move_horizontally() noexcept {
	last_step = 0;
	if (!is_active()) {
		Movable::move_horizontally();
		return;
	}
	const float next_distance = std::max(0.0f,
		std::min(patrol_distance, travelled_distance + hspeed));
	last_step = next_distance - travelled_distance;
	top_left.x += last_step;
	travelled_distance = next_distance;
	if (travelled_distance == 0 || travelled_distance == patrol_distance) {
		hspeed = -hspeed;
	}
}

void FlyingEnemy::move_vertically() noexcept {
	if (!is_active()) {
		Movable::move_vertically();
		return;
	}
	vspeed = 0;
}

void FlyingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	if (!is_active() || last_step == 0) {
		return;
	}
	top_left.x -= last_step;
	travelled_distance -= last_step;
	hspeed = last_step > 0 ? -std::abs(hspeed) : std::abs(hspeed);
	last_step = 0;
}

void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {}
