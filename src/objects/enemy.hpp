/**
	- Если создавать класс FlyableEenemy, JumpableEnemy и другие виды врагов, 
		то почему их нельзя наследовать от Enemy?
*/

#pragma once

#include "base_enemy.hpp"

namespace sea {
	class Enemy : public BaseEnemy {
		public:
			Enemy(const Coord& top_left, const int width, const int height);

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
