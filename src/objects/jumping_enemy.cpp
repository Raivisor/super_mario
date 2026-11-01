#include "jumping_enemy.hpp"

using sea::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left, const int width, const int height)
	: BaseEnemy(top_left, width, height) {}

void JumpingEnemy::move_horizontally() noexcept {}

void JumpingEnemy::move_vertically() noexcept {
	if (!is_active()) {
		Movable::move_vertically();
		return;
	}
	if (support && get_right() > support->get_left()
		&& get_left() < support->get_right()
		&& top_left.y + height == support->get_top()) {
		if (frames_until_jump > 0) {
			--frames_until_jump;
			return;
		}
		jump();
	}
	support = nullptr;
	Movable::move_vertically();
}

void JumpingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {}

void JumpingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	if (!is_active()) {
		return;
	}
	if (vspeed > 0) {
		top_left.y = obj->get_top() - height;
		support = obj;
		frames_until_jump = JUMP_PAUSE_FRAMES;
	} else if (vspeed < 0) {
		top_left.y = obj->get_bottom();
	}
	vspeed = 0;
}
