#include "second_level.hpp"

#include "third_level.hpp"

using sea::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

sea::GameLevel* SecondLevel::get_next() {
	if (!next) {
		clear_data();
		next = new sea::ThirdLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);

	// Safe starting area and the first flying enemy.
	ui_factory->create_ship({20, 25}, 55, 2);
	ui_factory->create_ship({90, 25}, 55, 2);
	ui_factory->create_flying_enemy({110, 22}, 3, 2, 15, 0.15f);

	// A jumping enemy with room to wait on either side.
	ui_factory->create_ship({160, 25}, 55, 2);
	ui_factory->create_jumping_enemy({187, 23}, 3, 2);

	// The sea gap requires a ride; the platform never overlaps either bank.
	ui_factory->create_ship({230, 25}, 25, 2);
	ui_factory->create_moving_platform({258, 25}, 12, 2, 55, 0.4f);
	ui_factory->create_ship({328, 25}, 50, 2);
	ui_factory->create_flying_enemy({350, 22}, 3, 2, 12, 0.15f);

	// Keep the finish last: Game uses the last static object as the exit.
	ui_factory->create_ship({395, 20}, 30, 7);
}
