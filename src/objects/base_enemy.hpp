#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect_map_movable_adapter.hpp"

namespace sea {
	class BaseEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
		protected:
			BaseEnemy(const Coord& top_left, const int width, const int height);

		public:
			virtual ~BaseEnemy() = default;

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override = 0;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override = 0;
	};
}
