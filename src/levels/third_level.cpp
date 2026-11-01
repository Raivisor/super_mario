#include "third_level.hpp"

using sea::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

sea::GameLevel* ThirdLevel::get_next() {
	return nullptr;
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

void ThirdLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);

	// Narrow islands alternate in height; every crossing needs a deliberate jump.
	ui_factory->create_ship({20, 25}, 38, 2);
	ui_factory->create_ship({80, 20}, 8, 7);
	ui_factory->create_ship({111, 25}, 7, 2);
	ui_factory->create_ship({142, 20}, 8, 7);
	ui_factory->create_ship({174, 25}, 7, 2);
	ui_factory->create_ship({205, 20}, 10, 7);
	ui_factory->create_ship({240, 25}, 9, 2);
	ui_factory->create_ship({273, 20}, 9, 7);
	ui_factory->create_ship({307, 25}, 8, 2);

	// Overhead boxes and patrolling enemies constrain takeoff and landing timing.
	ui_factory->create_box({111, 12}, 7, 2);
	ui_factory->create_box({240, 12}, 9, 2);
	ui_factory->create_enemy({143, 18}, 3, 2);
	ui_factory->create_enemy({242, 23}, 3, 2);

	// The last static object is the finish, as required by Game.
	ui_factory->create_ship({340, 20}, 16, 7);
}
