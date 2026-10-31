#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "moving_platform.hpp"

namespace sea {
	class ConsoleMovingPlatform : public MovingPlatform, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleMovingPlatform(
				const Coord& top_left, const int width, const int height,
				const float travel_distance, const float speed = 0.2f
			);

			char get_brush() const noexcept override;
	};
}
