#pragma once

#include "base_enemy.hpp"

namespace sea {
	class FlyingEnemy : public BaseEnemy {
		private:
			const float patrol_distance;
			float travelled_distance = 0;
			float last_step = 0;

		public:
			FlyingEnemy(
				const Coord& top_left, const int width, const int height,
				const float patrol_distance, const float speed = 0.2f
			);

			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;
			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
