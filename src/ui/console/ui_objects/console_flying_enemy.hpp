#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "flying_enemy.hpp"

namespace sea {
	class ConsoleFlyingEnemy : public FlyingEnemy, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleFlyingEnemy(
				const Coord& top_left, const int width, const int height,
				const float patrol_distance, const float speed = 0.2f
			);

			char get_brush() const noexcept override;
			bool is_visible() const noexcept override;
	};
}
