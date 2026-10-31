#pragma once

#include "ship.hpp"

namespace sea {
	class MovingPlatform : public Ship {
		private:
			const float travel_distance;
			float travelled_distance = 0;
			float speed;

		public:
			MovingPlatform(
				const Coord& top_left, const int width, const int height,
				const float travel_distance, const float speed = 0.2f
			);

			void move_horizontally() noexcept;
	};
}
