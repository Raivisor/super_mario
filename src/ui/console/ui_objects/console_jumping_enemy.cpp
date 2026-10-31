#include "console_jumping_enemy.hpp"

using sea::ConsoleJumpingEnemy;

ConsoleJumpingEnemy::ConsoleJumpingEnemy(
	const Coord& top_left, const int width, const int height
) : JumpingEnemy(top_left, width, height) {}

char ConsoleJumpingEnemy::get_brush() const noexcept {
	return 'j';
}

bool ConsoleJumpingEnemy::is_visible() const noexcept {
	return is_active();
}
