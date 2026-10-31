#pragma once

#include "base_enemy.hpp"

namespace sea {
	class JumpingEnemy : public BaseEnemy {
		private:
			static constexpr int JUMP_PAUSE_FRAMES = 10;
			const Rect* support = nullptr;
			int frames_until_jump = 0;

		public:
			JumpingEnemy(const Coord& top_left, const int width, const int height);

			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;
			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
