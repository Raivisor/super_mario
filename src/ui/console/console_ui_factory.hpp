#pragma once

#include <memory>

#include "console_box.hpp"
#include "console_enemy.hpp"
#include "console_flying_enemy.hpp"
#include "console_jumping_enemy.hpp"
#include "console_full_box.hpp"
#include "console_game_map.hpp"
#include "console_mario.hpp"
#include "console_money.hpp"
#include "console_ship.hpp"
#include "console_moving_platform.hpp"
#include "ui_factory.hpp"

namespace sea {
	class ConsoleUIFactory : public UIFactory {
		private:
			ConsoleGameMap* game_map = nullptr;
			std::vector<ConsoleBox*> boxes;
			std::vector<ConsoleFullBox*> full_boxes;
			std::vector<ConsoleShip*> ships;
			ConsoleMario* mario = nullptr;
			std::vector<ConsoleEnemy*> enemies;
			std::vector<std::unique_ptr<ConsoleFlyingEnemy>> flying_enemies;
			std::vector<std::unique_ptr<ConsoleJumpingEnemy>> jumping_enemies;
			std::vector<std::unique_ptr<ConsoleMovingPlatform>> moving_platforms;
			std::vector<ConsoleMoney*> moneys;

		public:
			ConsoleUIFactory(Game* game);
			
			void clear_data() override;
			void create_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_flying_enemy(
				const Coord& top_left, const int width, const int height,
				const float patrol_distance, const float speed = 0.2f
			) override;
			void create_jumping_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_full_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_mario(
				const Coord& top_left, const int width, const int height
			) override;
			void create_money(
				const Coord& top_left, const int width, const int height
			) override;
			void create_ship(
				const Coord& top_left, const int width, const int height
			) override;
			void create_moving_platform(
				const Coord& top_left, const int width, const int height,
				const float travel_distance, const float speed = 0.2f
			) override;
			GameMap* get_game_map(const int height, const int width) override;
			Mario* get_mario() override;
	};
}
