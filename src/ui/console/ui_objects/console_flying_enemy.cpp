#include "console_flying_enemy.hpp"

using sea::ConsoleFlyingEnemy;

ConsoleFlyingEnemy::ConsoleFlyingEnemy(
	const Coord& top_left, const int width, const int height,
	const float patrol_distance, const float speed
) : FlyingEnemy(top_left, width, height, patrol_distance, speed) {}

char ConsoleFlyingEnemy::get_brush() const noexcept {
	return 'f';
}

bool ConsoleFlyingEnemy::is_visible() const noexcept {
	return true;
}
