#include "console_moving_platform.hpp"

using sea::ConsoleMovingPlatform;

ConsoleMovingPlatform::ConsoleMovingPlatform(
	const Coord& top_left, const int width, const int height,
	const float travel_distance, const float speed
) : MovingPlatform(top_left, width, height, travel_distance, speed) {}

char ConsoleMovingPlatform::get_brush() const noexcept {
	return '=';
}
