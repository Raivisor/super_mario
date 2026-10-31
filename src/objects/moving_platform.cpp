#include "moving_platform.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

using sea::MovingPlatform;

MovingPlatform::MovingPlatform(
	const Coord& top_left, const int width, const int height,
	const float travel_distance, const float speed
) : Ship(top_left, width, height), travel_distance(travel_distance), speed(speed) {
	if (!std::isfinite(travel_distance) || travel_distance <= 0
		|| !std::isfinite(speed) || speed <= 0) {
		throw std::invalid_argument("MovingPlatform requires positive finite distance and speed");
	}
}

void MovingPlatform::move_horizontally() noexcept {
	const float next_distance = std::max(0.0f,
		std::min(travel_distance, travelled_distance + speed));
	top_left.x += next_distance - travelled_distance;
	travelled_distance = next_distance;
	if (travelled_distance == 0 || travelled_distance == travel_distance) {
		speed = -speed;
	}
}
