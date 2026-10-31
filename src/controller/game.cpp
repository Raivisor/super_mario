#include "game.hpp"

#include <algorithm>

using sea::Game;

Game::Game() {}

void Game::add_collisionable(Collisionable* obj) {
	collisionable_objs.push_back(obj);
}

void Game::add_map_movable(MapMovable* obj) {
	map_movable_objs.push_back(obj);
}

void Game::add_mario(Mario* obj) {
	mario = obj;
}

void Game::add_movable(Movable* obj) {
	movable_objs.push_back(obj);
}

void Game::add_static_obj(Rect* obj) {
	static_objs.push_back(obj);
}

void Game::add_moving_platform(MovingPlatform* obj) {
	moving_platforms.push_back(obj);
}

void Game::check_horizontally_static_collisions() noexcept {
	for (Collisionable* obj: collisionable_objs) {
		for (Rect* static_obj: static_objs) {
			if (obj->has_collision(static_obj)) {
				obj->process_horizontal_static_collision(static_obj);
				break;
			}
		}
	}
}

void Game::check_mario_collision() {
	for (int i = 0; i < collisionable_objs.size(); i++) {
		Collisionable* obj = collisionable_objs[i];
		if (obj->has_collision(mario)) {
			obj->process_mario_collision(mario);
			if (!mario->is_active()) {
				break;
			} else if (!obj->is_active()) {
				// TODO
				collisionable_objs[i] = collisionable_objs.back();
				collisionable_objs.pop_back();
				i--;
			}
		}
	}
}

bool Game::check_static_collisions(Collisionable* obj) const noexcept {
	for (Rect* static_obj: static_objs) {
		if (obj->has_collision(static_obj)) {
			return true;
		}
	}
	return false;
}

void Game::check_vertically_static_collisions() noexcept {
	if (mario->has_collision(static_objs[static_objs.size() - 1])) {
		is_level_end_ = true;
	}
	
	for (Collisionable* obj: collisionable_objs) {
		for (Rect* static_obj: static_objs) {
			const bool landing_on_platform = obj == mario && mario->get_vspeed() > 0
				&& mario->get_y() + mario->get_height() - mario->get_vspeed()
					<= static_obj->get_top() + 0.5f
				&& mario->get_y() + mario->get_height() >= static_obj->get_top()
				&& mario->get_right() > static_obj->get_left()
				&& mario->get_left() < static_obj->get_right()
				&& std::find(moving_platforms.begin(), moving_platforms.end(), static_obj)
					!= moving_platforms.end();
			if (obj->has_collision(static_obj) || landing_on_platform) {
				obj->process_vertical_static_collision(static_obj);
				if (landing_on_platform) {
					mario->move_vertical_offset(static_obj->get_top()
						- mario->get_height() - mario->get_y());
				}
				break;
			}
		}
	}
}

void Game::finish() noexcept {
	is_finished_ = true;
}

bool Game::is_finished() const noexcept {
	return is_finished_;
}

bool Game::is_level_end() const noexcept {
	return is_level_end_;
}

void Game::move_map_left() noexcept {
	for (MapMovable* obj: map_movable_objs) {
		obj->move_map_left();
	}
}

void Game::move_map_right() noexcept {
	for (MapMovable* obj: map_movable_objs) {
		obj->move_map_right();
	}
}

void Game::move_objs_horizontally() noexcept {
	for (Movable* obj: movable_objs) {
		obj->move_horizontally();
	}
}

void Game::move_objs_vertically() noexcept {
	for (Movable* obj: movable_objs) {
		obj->move_vertically();
	}
}

void Game::update_moving_platforms() noexcept {
	MovingPlatform* carrier = nullptr;
	if (mario && mario->is_active() && mario->get_vspeed() == 0) {
		for (MovingPlatform* platform: moving_platforms) {
			if (mario->get_bottom() == platform->get_top()
				&& mario->get_right() > platform->get_left()
				&& mario->get_left() < platform->get_right()) {
				carrier = platform;
				break;
			}
		}
	}
	for (MovingPlatform* platform: moving_platforms) {
		const float previous_x = platform->get_x();
		platform->move_horizontally();
		if (platform != carrier) {
			continue;
		}
		float offset = platform->get_x() - previous_x;
		const float mario_right = mario->get_x() + (mario->get_right() - mario->get_left());
		for (Rect* obstacle: static_objs) {
			if (obstacle == platform || mario->get_y() >= obstacle->get_bottom()
				|| mario->get_y() + mario->get_height() <= obstacle->get_top()) {
				continue;
			}
			if (offset > 0 && obstacle->get_right() > mario->get_x()) {
				offset = std::min(offset, std::max(0.0f,
					obstacle->get_left() - mario_right));
			} else if (offset < 0 && obstacle->get_left() < mario_right) {
				offset = std::max(offset, std::min(0.0f,
					obstacle->get_right() - mario->get_x()));
			}
		}
		mario->move_horizontal_offset(offset);
	}
}

void Game::remove_collisionable(Collisionable* obj) {
	remove_obj(collisionable_objs, obj);
}

void Game::remove_map_movable(MapMovable* obj) {
	remove_obj(map_movable_objs, obj);
}

void Game::remove_mario() noexcept {
	mario = nullptr;
}

void Game::remove_movable(Movable* obj) {
	remove_obj(movable_objs, obj);
}

void Game::remove_objs() {
	collisionable_objs.clear();
	map_movable_objs.clear();
	movable_objs.clear();
	static_objs.clear();
	moving_platforms.clear();
	remove_mario();
}

void Game::remove_static_obj(Rect* obj) {
	remove_obj(static_objs, obj);
}

void Game::start_level() noexcept {
	is_level_end_ = false;
}

// ----------------------------------------------------------------------------
// 									PRIVATE
// ----------------------------------------------------------------------------
template<class T>
void Game::remove_obj(std::vector<T*>& container, T* obj) {
	container.erase(
		std::remove(
			container.begin(), container.end(), obj
		), 
		container.end()
	);
}
